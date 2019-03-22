#include "CommandCreateRoom.h"
#include <boost/algorithm/string.hpp>

void CommandCreateRoom::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//TODO
    //if (role == admin) then allow to edit
    //else notify no permissions
    auto role = onlineUserManager.getUserRole(username);
    switch(role) {
        case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND:
            return "Please log in again.\n";
        case usermanager::OnlineUserManager::USER_CODE::USER_NORMAL_USER:
            //don't let normal user know that this syntax exists
            return "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
        case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN:
            // Need to implement createArea in Area class and add that method in WorldManager
            // Need to implement createRoom in Room class 
            return "YOU ARE THE ADMIN \n";
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
