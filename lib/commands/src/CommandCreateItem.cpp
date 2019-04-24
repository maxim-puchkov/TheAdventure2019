#include "CommandCreateItem.h"
#include <boost/algorithm/string.hpp>

void CommandCreateItem::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//TODO
    //if (role == admin) then allow to edit
    //else notify no permissions
    auto role = onlineUserManager.getUserRole(username);
    switch(role) {
        case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND: {
            std::string returnMessage =  "Please log in again.\n";
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
            worldManager.items.builder.setKeywords({fullCommand[1]});
            worldManager.items.builder.setDescription(fullCommand[2]);
            worldManager.items.create(location.room);
            // worldManager.items.print_contentsOf(location.room);
            std::cout << "Item name: " << fullCommand[1] << "\n";
            std::cout << "Item desc: " << fullCommand[2] << "\n";
            std::string returnMessage = "Item name: " + fullCommand[1] + " has been created\n";
            onlineUserManager.addMessageToUser(username, returnMessage);
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

std::vector<std::string> CommandCreateItem::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: create-item <name>: <description>
    commandIsValid = false;

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
