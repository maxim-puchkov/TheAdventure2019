#include "CommandLook.h"

void CommandLook::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = avatarManager.getAvatarLocation(username);
    if(location.area == -1) {
        //should not reach here, report error
        return;
    }
    
    onlineUserManager.addMessageToUser(username, (worldManager.look(location) + "\n"));
}


