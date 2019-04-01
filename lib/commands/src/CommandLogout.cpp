#include "CommandLogout.h"
#include <boost/algorithm/string.hpp>

using internationalization::Internationalization;

std::string CommandLogout::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	auto username = onlineUserManager.getUsernameFromConnectionID(connectionID);
    auto answer = onlineUserManager.logout(connectionID);
	switch(answer) {
		case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_OUT:
		{
            worldManager.kick(username, characterManager.getCharacterLocation(username));
            characterManager.kickCharacter(username);
			return stringManager.getString(Internationalization::STRING_CODE::NOW_LOGGED_OUT);;
		}
		case usermanager::OnlineUserManager::USER_CODE::USER_NOT_ONLINE:
			return (
                stringManager.getString(Internationalization::STRING_CODE::ERROR) + 
                " " +
                stringManager.getString(Internationalization::STRING_CODE::NOT_LOGGED_IN)
            );
		default:
            //should not get here, log error
        	break;
	}
	//swallow
    return "";
}

std::vector<std::string> CommandLogout::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: logout
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 1);
   
    return processedCommand;
}