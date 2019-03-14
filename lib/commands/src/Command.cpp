#include "Command.h"


//Default behavior: add command to action queue
std::string Command::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	//check if the avatar is fully customized to play or not
	auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);
	if (false/*characterManager.isCharacterFullyCustomized(username) != CharacterManager::CHARACTER_CODE::CHARACTER_IS_CUSTOMIZED*/) {
		return "Please customize your avatar first.\nEnter \"help Avatar\" for more information.\n"; 
	}


	bool success = onlineUserManager.onlineUserAddCommandToList(connectionID, fullCommand);
    if(!success) {
    	return "User is not online.\n";
    }
    //Do nothing, answer only when executing command 
    return "";
}


//Default behavior: swallow and log the error
void Command::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//Intended to be a null-function. Normally it should never reach this.
}