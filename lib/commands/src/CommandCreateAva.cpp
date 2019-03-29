#include "CommandCreateAva.h"
#include <boost/algorithm/string.hpp>

std::string CommandCreateAva::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	//Format: create-avatar <name> NPC
    if(fullCommand.size() == 3) {
        auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);
        auto role = onlineUserManager.getUserRole(username);
        switch(role) {
            case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND: {
                return "Please log in again.\n";
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_NORMAL_USER: {
                //don't let normal user know that this syntax exists
                return "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN: {
                //TODO: fill this
                auto answer = characterManager.createCharacter(username);
                switch(answer){
                    case charactermanager::CharacterManager::CHARACTER_CODE::CHARACTER_CREATED:{
                        auto roomToSpawnUser = worldManager.getRoomToSpawnUser();
                        characterManager.spawnCharacter(username, LocationCoordinates{0, roomToSpawnUser});
                        return "Avatar created.\nPlease enter \"edit-avatar shortdesc: [value]\" to customize your character.\n";
                    }
                    default: {
                        return "SHOULD NOT GET HERE";
                    }
                }
            }
            default:
                //swallow, log error state
                return "";
        }
    } else {
        //Format: create-avatar <name>
        auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);
        //kicked for being idle for too long
        if(username == "") {
            return "Please log in again.\n";
        }

        //TODO: split avatar name and username (now only use username)
        auto answer = characterManager.createCharacter(username);
        switch(answer) {
            case charactermanager::CharacterManager::CHARACTER_CODE::CHARACTER_CREATED: {
                auto roomToSpawnUser = worldManager.getRoomToSpawnUser();
                characterManager.spawnCharacter(username, LocationCoordinates{"Mirkwood", roomToSpawnUser});
                return "Avatar created.\nPlease enter \"edit-avatar shortdesc: [value]\" to customize your character.\n";
            }
            default:
            //error
                return "";
        }
    }
}

std::vector<std::string> CommandCreateAva::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: create-avatar <name>
    //Format: create-avatar <name> NPC
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() == 3) {
        commandIsValid = (processedCommand[2] == "NPC");
    } else {
        commandIsValid = (processedCommand.size() == 2);
    }
   
    return processedCommand;
}
