#include "CommandUse.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using boost::lexical_cast;
using boost::bad_lexical_cast;



void CommandUse::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    
    // Log out all users
    Command::onlineUserManager = OnlineUserManager();
    
}





std::vector<std::string> CommandUse::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: use [object-in-inventory]
    //Format: use [object-in-inventory] [object-index]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    if(processedCommand.size() == 3) {
        //check if [object-index] is a positive number
        try {
            commandIsValid = (lexical_cast<int>(processedCommand[2]) > 0);
        } catch(const bad_lexical_cast &) {
            commandIsValid = false;
        }

    } else {
        commandIsValid = (processedCommand.size() == 2);
    }
   
    return processedCommand;
}
