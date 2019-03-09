#include "CommandTell.h"

void CommandTell::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	std::string usernameOfListener = fullCommand[1];
    std::string message = fullCommand[2];
    std::string messageToSendOtherUser = username + " told you: " + message + "\n";

    if(onlineUserManager.addMessageToUser(usernameOfListener, messageToSendOtherUser)) {
        onlineUserManager.addMessageToUser(username, "You told " + usernameOfListener + ": \"" + message + "\"\n");
    } else {
    	onlineUserManager.addMessageToUser(username, "Failed to find online user with name: " + usernameOfListener + "\n");
    }
}


