#include "CommandLogin.h"

std::string CommandLogin::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto answer = onlineUserManager.login(connectionID, fullCommand[1], fullCommand[2]);
	switch(answer) {
		case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN:
		{
			auto spawnLocation = characterManager.spawnCharacter(fullCommand[1]);
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

std::vector<std::string> CommandLogin::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: login <username> <password>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 3);
   
    return processedCommand;
}