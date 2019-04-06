#include "CommandCreateRoom.h"
#include <boost/algorithm/string.hpp>

void CommandCreateRoom::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//TODO
    //if (role == admin) then allow to edit
    //else notify no permissions
    auto role = onlineUserManager.getUserRole(username);
    switch(role) {
        case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND: {
            std::string returnMessage =  stringManager.getString(Internationalization::STRING_CODE::PLEASE_LOG_IN_AGAIN);
            onlineUserManager.addMessageToUser(username, returnMessage);
            return;
        }
        case usermanager::OnlineUserManager::USER_CODE::USER_NORMAL_USER: {
            //don't let normal user know that this syntax exists
            std::string returnMessage =  "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
            onlineUserManager.addMessageToUser(username, returnMessage);
            return;
        }
        case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN: {
            auto location = characterManager.getCharacterLocation(username);
            worldManager.createRoom(location, fullCommand[1], fullCommand[2]);
            std::string returnMessage = "Room: " + fullCommand[2] + " has been created\n";
            onlineUserManager.addMessageToUser(username, returnMessage);
        }
        case usermanager::OnlineUserManager::USER_CODE::INVALID_USERNAME: {} 
        case usermanager::OnlineUserManager::USER_CODE::ACCOUNT_CREATED: {} 
        case usermanager::OnlineUserManager::USER_CODE::USER_UPDATED: {} 
        case usermanager::OnlineUserManager::USER_CODE::USER_DELETED: {} 
        case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_OUT: {} 
        case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN: {}
        case usermanager::OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN: {}
        case usermanager::OnlineUserManager::USER_CODE::USER_NOT_ONLINE: {}   
    }
}

std::vector<std::string> CommandCreateRoom::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: create-room <direction> <name>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 3);
    return processedCommand;
}
