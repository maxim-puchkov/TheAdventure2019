#include "CommandCombat.h"
#include <boost/algorithm/string.hpp>

void CommandCombat::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    //fill this
}

std::vector<std::string> CommandCombat::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: combat challenge [username]
    //Format: combat accept
    //Format: combat accept [username]
    //Format: combat join [username]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " "
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);        
    if(processedCommand.size() == 2) {
        commandIsValid = (processedCommand[1] == "accept");
    
    } else if(processedCommand.size() == 3) {
        //reassemble the command
        commandIsValid = (processedCommand[1] == "accept" ||
                            processedCommand[1] == "join" ||
                            processedCommand[1] == "challenge");
    } else {
        commandIsValid = false;
    }

    return processedCommand;
}