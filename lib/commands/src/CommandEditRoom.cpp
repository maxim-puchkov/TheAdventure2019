#include "CommandEditRoom.h"
#include <boost/algorithm/string.hpp>

void CommandEditRoom::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    //TODO
    //if (role == admin) then allow to edit
    //else notify no permissions
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
            // Need to implement createArea in Area class and add that method in WorldManager
            // Need to implement createRoom in Room class 
            std::cout <<  "YOU ARE THE ADMIN \n";
            // std::cout << "Area: " << location.area << "\n";
            // std::cout << "Room: " << location.room << "\n";
        }
        default: {return;}
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
