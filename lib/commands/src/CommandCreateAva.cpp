#include "CommandCreateAva.h"

std::string CommandCreateAva::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
	// TODO: check user privilege to allow the second format
    return "";
}

std::vector<std::string> CommandCreateAva::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: create-avatar <name>
    //Format: create-avatar <name> NPC
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() == 3) {
        commandIsValid = (processedCommand[2] == "NPC");
    } else {
        commandIsValid = (processedCommand.size() == 2);
    }
   
    return processedCommand;
}
