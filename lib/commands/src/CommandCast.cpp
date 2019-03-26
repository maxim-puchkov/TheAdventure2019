#include "CommandCast.h"
#include <boost/algorithm/string.hpp>

void CommandCast::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//fill this
}

std::vector<std::string> CommandCast::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: cast [spell-name]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 2);

    return processedCommand;
}