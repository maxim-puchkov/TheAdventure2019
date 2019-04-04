#include "CommandLogin.h"
#include <boost/algorithm/string.hpp>

using internationalization::Internationalization;

std::string CommandLogin::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto userLoginCode = onlineUserManager.login(connectionID, fullCommand[1], fullCommand[2]);
	switch(userLoginCode) {
		case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN:
		{
			std::stringstream reply;
			reply << stringManager.getString(Internationalization::STRING_CODE::NOW_LOGGED_IN);

			if(!characterManager.isCharacterCreated(fullCommand[1])) {
				reply << stringManager.getString(Internationalization::STRING_CODE::AVATAR_IS_REQUIRED);
				reply << stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER) << "\"";
				reply << stringManager.getString(Internationalization::STRING_CODE::COMMAND_CREATE_AVATAR);
				reply << "[" << stringManager.getString(Internationalization::STRING_CODE::NAME) << "]\"";
				reply << stringManager.getString(Internationalization::STRING_CODE::TO_CREATE);
				//reply << "An avatar is required to play the game. Please input \"create-avatar [name]\" to create.\n";
			} else {
				//tmr, when user login, get the location from json, then pass to characterManager
				// if user is first time, then get the first area name from worldManager.
				auto roomToSpawnUser = worldManager.getRoomToSpawnUser();
				auto spawnLocation = characterManager.spawnCharacter(fullCommand[1], LocationCoordinates{"Mirkwood", roomToSpawnUser});
				auto room = worldManager.findRoomByLocation(spawnLocation);
			    worldManager.spawn(fullCommand[1], spawnLocation);	    
			    reply << stringManager.getString(Internationalization::STRING_CODE::CURRENT_LOCATION);
				reply << stringManager.getString(Internationalization::STRING_CODE::AREA);
				reply << ": ";
				reply << spawnLocation.area;
				reply << (", ", stringManager.getString(Internationalization::STRING_CODE::ROOM), ": ");
				reply << room.getName();
				reply << "\n";
			}

			return reply.str();
		}
		case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND:
			return (stringManager.getString(Internationalization::STRING_CODE::ERROR) + " " +
					stringManager.getString(Internationalization::STRING_CODE::USERNAME_NOT_FOUND) + " " +
					stringManager.getString(Internationalization::STRING_CODE::PLEASE_TRY_AGAIN));

		case usermanager::OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN:
			return (stringManager.getString(Internationalization::STRING_CODE::ERROR) + " " +
					stringManager.getString(Internationalization::STRING_CODE::ALREADY_LOGGED_IN));
        default:
            //should not reach here. log the error
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