#include "CommandYell.h"

void CommandYell::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
    	//should not reach here, report error
    	return;
    }
    
    auto& userNamesInRoom = worldManager.getUserNamesInRange(location, YELL_RANGE);
    for(auto name: userNamesInRoom) {
    	if(name == username) {
    		continue;
    	}
        onlineUserManager.addMessageToUser(name, username + " yelled: \"" + fullCommand[1] + "\"\n");
    }

    onlineUserManager.addMessageToUser(username, "You yelled: \"" + fullCommand[1] + "\"\n");
}


