#include "CommandCreateRoom.h"

void CommandCreateRoom::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	//TODO
    //if (role == admin) then allow to edit
    //else notify no permissions
}

std::vector<std::string> CommandCreateRoom::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: create-room <direction> <name>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 3);
   
    return processedCommand;
}
