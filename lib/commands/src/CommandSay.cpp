#include "CommandSay.h"

void CommandSay::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
    	//should not reach here, report error
    	return;
    }
    
    auto& userNamesInRoom = worldManager.getUserNamesInRange(location, SAY_RANGE);
    for(auto name: userNamesInRoom) {
    	if(name == username) {
    		continue;
    	}
        onlineUserManager.addMessageToUser(name, username + " said: \"" + fullCommand[1] + "\"\n");
    }

    onlineUserManager.addMessageToUser(username, "You said: \"" + fullCommand[1] + "\"\n");
}


