#include "CommandCreate.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

using internationalization::Internationalization;

std::string CommandCreate::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto answer = onlineUserManager.createUser(fullCommand[1], fullCommand[2]);
	switch(answer) {
		case UserDB::DB_CODE::INVALID_USERNAME:
            return (
                stringManager.getString(Internationalization::STRING_CODE::ERROR) + 
                " " +
                stringManager.getString(Internationalization::STRING_CODE::INVALID_USERNAME)
            );

		case UserDB::DB_CODE::ACCOUNT_CREATED:
			return stringManager.getString(Internationalization::STRING_CODE::ACCOUNT_CREATED);
		default:
            //error, should never get here, log problem
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
    commandIsValid = (processedCommand.size() == 3);

    return processedCommand;
}