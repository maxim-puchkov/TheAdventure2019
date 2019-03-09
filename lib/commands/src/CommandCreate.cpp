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

std::vector<std::string> CommandCreate::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: create-account <username> <password>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() != 3) {
        commandIsValid = false;
    } else {
    	commandIsValid = true;
    }
   
    return processedCommand;
}