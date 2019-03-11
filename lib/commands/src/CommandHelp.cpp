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
    answer << "create-avatar [name]\n";
    answer << "edit-avatar: [what-to-edit] [value]\n";
    answer << "help\n";
    answer << "--------------------------------------------------\n";

    //edit-avatar [name-of-NPC] [what-to-edit]: [value]
    //edit-room [what-to-edit]: [value]
    //create-avatar [name] NPC
    //create-room [direction] [name]
    //use [object-in-inventory]
    //use [object-in-inventory] [object-index]
    //equip [object-in-inventory]
    //equip [object-in-inventory] [object-index] 
    //pickup [object]
    //pickup [object] [object-index]
    //drop [object-in-inventory]
    //drop [object-in-inventory] [object-index]
    //put [container-name]
    //put [container-name] [container-index]  
    //minigame challenge [username]
    //minigame accept
    //minigame accept [username]
    //minigame join [username]
    //minigame move [location-of-piece-to-be-moved],[new-location]  
    //combat challenge [username]
    //combat accept
    //combat accept [username]
    //combat join [username] 
    //attack
    //flee
    //cast [spell-name] (swap, decoy, confuse)


    //look [object/username]
    //look [object/username] [object/username-index]
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