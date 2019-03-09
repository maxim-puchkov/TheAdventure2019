#include "CommandHelp.h"

std::string CommandHelp::executePromptReply(const std::string& connectionID, const std::vector<std::string>& fullCommand) {
    std::stringstream answer;
    
    answer << "Supported commands: \n";
    answer << "--------------------------------------------------\n";
    answer << "login [username] [password]\n";
    answer << "logout\n";
    answer << "create-account [username] [password]\n";
    answer << "say: [message]\n";
    answer << "yell: [message]\n";
    answer << "tell [other-username]: [message]\n";
    answer << "move [direction]\n";
    answer << "look\n";
    answer << "examine [object/username]\n";
    answer << "help\n";
    answer << "--------------------------------------------------\n";

    return answer.str();
}

std::vector<std::string> CommandHelp::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: help
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() != 1) {
        commandIsValid = false;
    } else {
        commandIsValid = true;
    }
   
    return processedCommand;
}