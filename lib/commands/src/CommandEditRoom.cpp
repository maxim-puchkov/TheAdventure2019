#include "CommandEditRoom.h"
#include <boost/algorithm/string.hpp>

void CommandEditRoom::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    //TODO
    //if (role == admin) then allow to edit
    //else notify no permissions
}

std::vector<std::string> CommandEditRoom::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;
    commandIsValid = false;

    //Format: edit-room <what-to-edit>: <value>
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
