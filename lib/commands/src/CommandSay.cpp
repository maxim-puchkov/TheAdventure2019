#include "CommandSay.h"

void CommandSay::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
    	//should not reach here, report error
    	return;
    }
    
    auto& userNamesInRoom = worldManager.getUserNamesInRoom(location);
    for(auto& name: userNamesInRoom) {
        if(name == username) {
    		onlineUserManager.addMessageToUser(username, "You said: \"" + fullCommand[1] + "\"\n");
    	}
        onlineUserManager.addMessageToUser(name, username + " said: \"" + fullCommand[1] + "\"\n");
    }    
}

std::vector<std::string> CommandSay::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: say : <message>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //Split by ":" and compress all spaces on both sides of ":"
    std::vector<std::string> splitByColon;
    boost::split(splitByColon, fullCommand, boost::is_any_of(":"), boost::token_compress_on);
    if(splitByColon.size() != 2) {
        commandIsValid = false;
        return processedCommand;
    }

    //trim any space before and after ":"
    boost::trim_if(splitByColon[0], boost::is_any_of(" \t"));
    boost::trim_if(splitByColon[1], boost::is_any_of(" \t"));

    //split the left side of ":" by " "
    boost::split(processedCommand, splitByColon[0], boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() != 1) {
        commandIsValid = false;
        return processedCommand;
    }

    //reassemble the command
    processedCommand.push_back(splitByColon[1]);
    commandIsValid = true;
    return processedCommand;
}