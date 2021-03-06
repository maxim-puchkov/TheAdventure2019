#include "CommandEditRoom.h"
#include <boost/algorithm/string.hpp>

void CommandEditRoom::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
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
            // Need to implement createArea in Area class and add that method in WorldManager
            // Need to implement createRoom in Room class
            // edit-room exit: <direction>, <target room ID>
            // can only connect room in the same area
            if(fullCommand.at(1) == stringManager.getString(Internationalization::STRING_CODE::EXIT)) { 
                std::vector<std::string> splitByComma;
                boost::split(splitByComma, fullCommand[2], boost::is_any_of(","), boost::token_compress_on);
                boost::trim_if(splitByComma[1], boost::is_any_of(" \t"));
            
                auto location = characterManager.getCharacterLocation(username);
                auto targetArea = worldManager.getAreaByLocation(location);
                if(targetArea.getName() != stringManager.getString(Internationalization::STRING_CODE::DEFAULT_NAME)){
                    auto targetRoom = targetArea.getRoom(stoi(splitByComma[1]));
                    if(targetRoom.getName() != stringManager.getString(Internationalization::STRING_CODE::NO_ROOM_NAME)) {
                        auto& currentRoom = worldManager.findRoomByLocation(location);
                        currentRoom.createExit(
                            "-1",
                            stringManager.getString(Internationalization::STRING_CODE::ADMIN_EXIT), 
                            splitByComma[0], 
                            location.area, 
                            stoi(splitByComma[1])
                        );

                        auto& exitList = currentRoom.getExits();
                        for(auto& ext : exitList) {
                            if(ext.getExitName() == "-1"){
                                std::string exitName = 
                                    stringManager.getString(Internationalization::STRING_CODE::EXIT_TO) +
                                    " " +
                                    stringManager.getString(Internationalization::STRING_CODE::AREA) + 
                                    ": " + 
                                    location.area;
                                exitName += 
                                    " " + 
                                    stringManager.getString(Internationalization::STRING_CODE::ROOM) + 
                                    ": " + 
                                    targetRoom.getName();
                                ext.setExitTargetLocation(exitName);
                                break;
                            }
                        }
                    }
                }
            }else if(fullCommand.at(1) == stringManager.getString(Internationalization::STRING_CODE::DESC)) {
                auto location = characterManager.getCharacterLocation(username);
                auto& room = worldManager.findRoomByLocation(location);
                room.setDescription(fullCommand.at(2));

            }
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

std::vector<std::string> CommandEditRoom::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;
    commandIsValid = false;

    //Format: edit-room <what-to-edit>: <value>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //Split by ":"
    std::vector<std::string> splitByColon;
    boost::split(splitByColon, fullCommand, boost::is_any_of(":"), boost::token_compress_on);
    if(splitByColon.size() != 2) {  
        return processedCommand;
    }

    //trim any space before and after ":"
    boost::trim_if(splitByColon[0], boost::is_any_of(" \t"));
    boost::trim_if(splitByColon[1], boost::is_any_of(" \t"));

    //split the left side of ":" by " "
    boost::split(processedCommand, splitByColon[0], boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() != 2) {
        return processedCommand;
    }

    //reassemble the command
    processedCommand.push_back(splitByColon[1]);
    commandIsValid = true;
    return processedCommand;
}
