#include "CommandAttack.h"
#include <boost/algorithm/string.hpp>

void CommandAttack::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//fill this
}

std::vector<std::string> CommandAttack::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: attack
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 1);

    return processedCommand;
}