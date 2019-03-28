#include "CommandTake.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>


using boost::lexical_cast;
using boost::bad_lexical_cast;


// Execute command
void CommandTake::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    
    // Find where character is
    auto location = Command::characterManager.getCharacterLocation(username);
    
    // Then find the actual room...
    auto room = Command::worldManager.findRoomByLocation(location);
    
    // Get the input keyword
    auto keyword = fullCommand[0];
    
    // Find the object
    /*
    if (room.items.contain(itemKeyword)) {
        auto itemIdentifier = room.items.get(keyword));
        Command::characterManager.addItemToCharacter(username, itemIdentifier);
    }
     */
    
}


// Internal command validation
std::vector<std::string> CommandTake::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: pickup [object-in-inventory]
    //Format: pickup [object-in-inventory] [object-index]
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
