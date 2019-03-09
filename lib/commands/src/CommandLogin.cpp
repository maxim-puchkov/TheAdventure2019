#include "CommandLogin.h"

std::string CommandLogin::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto answer = onlineUserManager.login(connectionID, fullCommand[1], fullCommand[2]);
	switch(answer) {
		case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN:
		{
			auto spawnLocation = avatarManager.spawnAvatar(fullCommand[1]);
		    worldManager.spawn(fullCommand[1], spawnLocation);
			return "You are now logged in.\n";
		}
		case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND:
			return "Error! Username not found. Please try again.\n";
		case usermanager::OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN:
			return "Error! You are already logged in.\n";
        default:
            std::cout << "ERROR SHOULD NOT GET HERE! \n";
        break;
	}
	//swallow
    return "";
}


