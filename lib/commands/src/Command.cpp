#include "Command.h"

using internationalization::Internationalization;

//Default behavior: add command to action queue
std::string Command::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	//check if the avatar is fully customized to play or not
	auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);

	/*
	if (characterManager.isCharacterFullyCustomized(username) != CharacterManager::CHARACTER_CODE::CHARACTER_IS_CUSTOMIZED) {
		return (stringManager.getString(Internationalization::STRING_CODE::PLEASE_CUSTOMIZE_AVATAR_FIRST) + " " +
				stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER) + " \"" +
				stringManager.getString(Internationalization::STRING_CODE::COMMAND_HELP) + " " +
				stringManager.getString(Internationalization::STRING_CODE::AVATAR) + "\" " +
				stringManager.getString(Internationalization::STRING_CODE::TO_SEE_MORE_INFO)
		);
	}*/


	bool success = onlineUserManager.onlineUserAddCommandToList(connectionID, fullCommand);
    if(!success) {
    	return stringManager.getString(Internationalization::STRING_CODE::USER_NOT_ONLINE);
    }
    //Do nothing, answer only when executing command 
    return "";
}


//Default behavior: swallow and log the error
void Command::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//Intended to be a null-function. Normally it should never reach this.
}