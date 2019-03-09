#include "CommandCreate.h"

std::string CommandCreate::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto answer = onlineUserManager.createUser(fullCommand[1], fullCommand[2]);
	switch(answer) {
		case UserDB::DB_CODE::INVALID_USERNAME:
			return "Error! Invalid username.\n";
		case UserDB::DB_CODE::ACCOUNT_CREATED:
			return "Account created. Please log in to play the game.\n";
		default:
            std::cout << "ERROR SHOULD NOT GET HERE! \n";
        break;
	}
	//swallow
    return "";
}


