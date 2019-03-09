#include "CommandLook.h"

void CommandLook::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
        //should not reach here, report error
        return;
    }
    
    onlineUserManager.addMessageToUser(username, (worldManager.look(location) + "\n"));
}

std::vector<std::string> CommandLook::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: look
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() != 1) {
        commandIsValid = false;
    } else {
    	commandIsValid = true;
    }
   
    return processedCommand;
}