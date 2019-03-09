#include "CommandExamine.h"

void CommandExamine::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
    	//should not reach here, report error
    	return;
    }

	if(fullCommand[1] == "exits")
	    onlineUserManager.addMessageToUser(username, (worldManager.listExits(location) + "\n"));
	else
	    onlineUserManager.addMessageToUser(username, (worldManager.look(location, fullCommand[1]) + "\n"));
}


