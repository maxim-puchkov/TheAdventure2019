#include "CommandTake.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>


using boost::lexical_cast;
using boost::bad_lexical_cast;


// Execute command
void CommandTake::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    
    // Find character's location
    auto location = Command::characterManager.getCharacterLocation(username);
    
    // Then find the actual room
    auto room = Command::worldManager.findRoomByLocation(location);
    
    // Keyword is the second element of the vector
    auto keyword = fullCommand.at(1);
    
    // Find all items matching this keyword
    // Searching whole world because rooms don't have items
    auto ids = Command::worldManager.items.search(std::move(keyword));
    
    if (ids.size() == 1) {
        // If there is exactly one item matching
        auto itemID = ids[0];
        auto inventory = Command::characterManager.getCharacterInventory(username);
        inventory.add(itemID);
    } else {
        // Else two or more items have the same keyword...
    }
    
    
    
    
    /* Debugging */
    
    debug::prefix("CommandTake");
    
    // Note: location.room actually means the id of the room
    debug::print("Room: ", room.getName(), " (id: ", location.room, ")");
    debug::print("Keyword: ", keyword, '\n');
    
    debug::print("Found ", ids.size(), " items matching the keyword");

    
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
