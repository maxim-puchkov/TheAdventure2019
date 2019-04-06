#include "CommandLogin.h"
#include <boost/algorithm/string.hpp>

std::string CommandLogin::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto userLoginCode = onlineUserManager.login(connectionID, fullCommand[1], fullCommand[2]);
	switch(userLoginCode) {
		case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN:
		{
			std::stringstream reply;
			reply << "You are now logged in.\n";

			if(!characterManager.isCharacterCreated(fullCommand[1])) {
				reply << "An avatar is required to play the game. Please input \"create-avatar [name]\" to create.\n";
			} else {
				//tmr, when user login, get the location from json, then pass to characterManager
				// if user is first time, then get the first area name from worldManager.
				auto roomToSpawnUser = worldManager.getRoomToSpawnUser();
				auto areaToSpawnUser = worldManager.getAreaToSpawnUser();
				auto spawnLocation = LocationCoordinates{areaToSpawnUser, roomToSpawnUser};
				std::string spawnArea = characterManager.getCharArea(fullCommand[1]);
				int spawnRoom = characterManager.getCharRoom(fullCommand[1]);
				if(spawnArea != "" && spawnRoom != -1) {
					spawnLocation = characterManager.spawnCharacter(fullCommand[1], LocationCoordinates{spawnArea, spawnRoom});
				}else{
					spawnLocation = characterManager.spawnCharacter(fullCommand[1], spawnLocation);
				}
				//auto room = worldManager.findRoomByLocation(spawnLocation);
				if(worldManager.findRoomByLocation(spawnLocation).getName() == "NO_ROOM_NAME"){
					std::cout << roomToSpawnUser << "\n";
					spawnLocation = LocationCoordinates{areaToSpawnUser, roomToSpawnUser};
				}
				//room = worldManager.findRoomByLocation(spawnLocation);
			    worldManager.spawn(fullCommand[1], spawnLocation);	    
			    reply << "Current location: Area:" << spawnLocation.area << ", Room: " << worldManager.findRoomByLocation(spawnLocation).getName() << "\n";
			}

			return reply.str();
		}
		case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND:
			return "Error! Username not found. Please try again.\n";
		case usermanager::OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN:
			return "Error! You are already logged in.\n";
        default:
            std::cout << "ERROR SHOULD NOT GET HERE! \n";
        break;
	}
	//swallow
    return "";
}

std::vector<std::string> CommandLogin::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: login <username> <password>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 3);
    return processedCommand;
}
