#include "CommandAdmin.h"
#include <boost/algorithm/string.hpp>

void CommandAdmin::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
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
            std::string returnMessage =  (
                    stringManager.getString(Internationalization::STRING_CODE::WRONG_COMMAND_SYNTAX), 
                    stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER_HELP_SYNTAX)
                );;
            onlineUserManager.addMessageToUser(username, returnMessage);
            return;
        }
        case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN: {
            std::string returnMessage = 
                stringManager.getString(Internationalization::STRING_CODE::ADMIN_INVALID_USER);
            bool userFound = false;
            auto location = characterManager.getCharacterLocation(username);
            auto userInRoom = worldManager.getUserNamesInRoom(location);
            for(auto user : userInRoom){
                if(user == fullCommand[1]){
                    userFound = true;
                    break;
                }
            }
            if(userFound){
                auto& promoUser = onlineUserManager.getUserByUsername(fullCommand[1]);
                promoUser.setRole(User::USER_ROLE::ADMIN);
                returnMessage = 
                    "User: " + 
                    fullCommand[1] + 
                    stringManager.getString(Internationalization::STRING_CODE::ADMIN_IS_PROMOTED);
                onlineUserManager.addMessageToUser(username, returnMessage);
                returnMessage = 
                    stringManager.getString(Internationalization::STRING_CODE::ADMIN_YOUVE_BEEN_PROMOTED);
                onlineUserManager.addMessageToUser(fullCommand[1], returnMessage);
                return;
            }else{
                onlineUserManager.addMessageToUser(username, returnMessage);
            }
            return;
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

std::vector<std::string> CommandAdmin::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;
    commandIsValid = false;

    //Format: admin <username>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 2);

    return processedCommand;
}