#include "CommandLook.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;
using boost::bad_lexical_cast;

void CommandLook::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = characterManager.getCharacterLocation(username);
    if(location.area == "") {
        //should not reach here, report error
        return;
    }

    if(fullCommand.size() < 2) {
        onlineUserManager.addMessageToUser(username, (worldManager.look(location) + "\n"));
        return;
    }

    if(fullCommand.at(1) == "exits"){
        onlineUserManager.addMessageToUser(username, (worldManager.listExits(location) + "\n"));
    } else {
        onlineUserManager.addMessageToUser(username, (worldManager.look(location, fullCommand.at(1)) + "\n"));
    }

    //use for admin. look world => output the list of room
    //TODO: for some reasons the server does not print the full string
    //      if the string is too long. Only print the second half of the string.
    if(fullCommand.at(1) == "world"){
        auto role = onlineUserManager.getUserRole(username);
        switch(role) {
            case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND: {
                std::cout << "Please log in again.\n";
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_NORMAL_USER: {
                //don't let normal user know that this syntax exists
                std::cout <<  "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN: {
                auto location = characterManager.getCharacterLocation(username);
                auto resultMessage = worldManager.worldDetail(location);
                onlineUserManager.addMessageToUser(username, resultMessage);
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

}

std::vector<std::string> CommandLook::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: look
    //Format: look [object/username]
    //format: look [object/username] [object/username-index]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() == 3) {
        //check if [object-index] is a positive number
        try {
            commandIsValid = (lexical_cast<int>(processedCommand[2]) > 0);
        } catch(const bad_lexical_cast &) {
            commandIsValid = false;
        }

    } else {
        commandIsValid = (processedCommand.size() == 2 || processedCommand.size() == 1);
    }
   
    return processedCommand;
}