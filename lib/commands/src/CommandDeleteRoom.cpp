#include "CommandDeleteRoom.h"
#include <boost/algorithm/string.hpp>

void CommandDeleteRoom::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//TODO
    //if (role == admin) then allow to edit
    //else notify no permissions
    auto role = onlineUserManager.getUserRole(username);
    switch(role) {
        case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND: {
            std::string returnMessage = stringManager.getString(Internationalization::STRING_CODE::PLEASE_LOG_IN_AGAIN);
            onlineUserManager.addMessageToUser(username, returnMessage);
            return;
        }
        case usermanager::OnlineUserManager::USER_CODE::USER_NORMAL_USER: {
            //don't let normal user know that this syntax exists
            std::string returnMessage =  (
                stringManager.getString(Internationalization::STRING_CODE::WRONG_COMMAND_SYNTAX), 
                stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER_HELP_SYNTAX)
            );
            onlineUserManager.addMessageToUser(username, returnMessage);
            return;
        }
        case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN: {
            std::string returnMessage;
            auto location = characterManager.getCharacterLocation(username);
            if(location.room == stoi(fullCommand[1])){
                onlineUserManager.addMessageToUser(
                    username, 
                    stringManager.getString(Internationalization::STRING_CODE::DELETING_ROOM_YOU_ARE_IN)
                );
            }else{
                auto result = worldManager.deleteRoom(LocationCoordinates{location.area, stoi(fullCommand[1])});
                if(result){
                    returnMessage = 
                        stringManager.getString(Internationalization::STRING_CODE::DELETING_ROOM_MESSAGE) + 
                        fullCommand[1] + 
                        stringManager.getString(Internationalization::STRING_CODE::IN_AREA) + 
                        location.area + 
                        "\n";
                }else{
                    returnMessage = 
                        stringManager.getString(Internationalization::STRING_CODE::INVALID_ROOM_ENTER);
                }
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

std::vector<std::string> CommandDeleteRoom::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: delete-room <room ID>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 2);
    return processedCommand;
}