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