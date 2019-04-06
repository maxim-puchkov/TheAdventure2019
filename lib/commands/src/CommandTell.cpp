#include "CommandTell.h"
#include <boost/algorithm/string.hpp>

using internationalization::Internationalization;

void CommandTell::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	std::string usernameOfListener = fullCommand[1];
    std::string message = fullCommand[2];
    std::string messageToSendOtherUser = username + 
                                        stringManager.getString(Internationalization::STRING_CODE::TOLD) + " " +
                                        stringManager.getString(Internationalization::STRING_CODE::YOU) + ": " +
                                        message + "\n";
    
    std::string notificationToSender = stringManager.getString(Internationalization::STRING_CODE::YOU) + " " +
                                        stringManager.getString(Internationalization::STRING_CODE::TOLD) + " " +
                                        usernameOfListener + ": \"" + message + "\"\n";

    if(onlineUserManager.addMessageToUser(usernameOfListener, messageToSendOtherUser)) {
        onlineUserManager.addMessageToUser(username, notificationToSender);
    } else {
        std::string failedMessage = stringManager.getString(Internationalization::STRING_CODE::FAILED_TO_FIND_WITH_NAME) +
                                    usernameOfListener + "\n";

    	onlineUserManager.addMessageToUser(username, failedMessage);
    }
}

std::vector<std::string> CommandTell::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
	std::vector<std::string> processedCommand;
    commandIsValid = false;

	//Format: tell <username> : <message>
	boost::trim_if(fullCommand, boost::is_any_of(" \t"));

	//Split by ":"
	std::vector<std::string> splitByColon;
	boost::split(splitByColon, fullCommand, boost::is_any_of(":"), boost::token_compress_on);
	if(splitByColon.size() != 2) {	
		return processedCommand;
	}

	//trim any space before and after ":"
    boost::trim_if(splitByColon[0], boost::is_any_of(" \t"));
    boost::trim_if(splitByColon[1], boost::is_any_of(" \t"));

    //split the left side of ":" by " "
    boost::split(processedCommand, splitByColon[0], boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() != 2) {
    	return processedCommand;
    }

    //reassemble the command
    processedCommand.push_back(splitByColon[1]);
    commandIsValid = true;
    return processedCommand;
}