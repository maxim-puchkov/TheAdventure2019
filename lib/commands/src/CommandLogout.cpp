#include "CommandLogout.h"

std::string CommandLogout::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);
    auto answer = onlineUserManager.logout(connectionID);
	switch(answer) {
		case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_OUT:
		{
            worldManager.kick(username, avatarManager.getAvatarLocation(username));
            avatarManager.kickAvatar(username);
			return "You are now logged out.\n";
		}
		case usermanager::OnlineUserManager::USER_CODE::USER_NOT_ONLINE:
			return "Error! You are not logged in.\n";
		default:
            std::cout << "ERROR SHOULD NOT GET HERE! \n";
        	break;
	}
	//swallow
    return "";
}


