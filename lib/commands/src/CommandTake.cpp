#include "CommandTake.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "print.h"

using boost::lexical_cast;
using boost::bad_lexical_cast;


/// Execute command
void CommandTake::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {

    debug::prefix("TAKE");
    
    
    // Find character's location
    auto location = Command::characterManager.getCharacterLocation(username);

    
    // Room owns items that may be taken
    // Note: location.room actually means the id of the room
    auto room_id = location.room;
    
    
    // Keyword is the second element of the vector
    auto keyword = fullCommand.at(1);

    
    // Search for identifiers of all items matching the keyword
    auto ids = Command::worldManager.items.search(room_id, keyword);


    // Recepient of the item
    auto character_id = 100;

    
    // Debug
    debug::print("Searched keyword: ", keyword);
    debug::print("In room id = ", room_id);
    debug::print("By character id = ", character_id);
    debug::print("Matching items found: ", ids.size());
    debug::print("Total count of created items: ", Command::worldManager.items.itemsCreated());
    
    // Otherwise, an error message containing all matching items is sent
    // to the user so they can choose another unambigious keyword, or
    // select item to take by its identifier
    if (ids.size() != 1) {
        debug::print("Ambiguous search");
        /* ... */
        return;
    }
    
    
    
    
    debug::print("Items in the room before update: ",
          Command::worldManager.items.containerSize(room_id));
    debug::print("Items in character's inventory before update: ",
          Command::worldManager.items.containerSize(character_id));
    
    
    // If search is not ambiguous, owner will be changed from
    // room_id to character_id
    auto item_id = ids[0];
    Command::worldManager.items.reassign(room_id, character_id, item_id);
    
    
    debug::print("Item id = ", item_id,
          " was reassigned from ", room_id,
          " to ", character_id);
    
    debug::print("Items in the room after update: ",
          Command::worldManager.items.containerSize(room_id));
    debug::print("Items in character's inventory after update: ",
          Command::worldManager.items.containerSize(character_id));
    
    
}


/// Internal command validation
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
