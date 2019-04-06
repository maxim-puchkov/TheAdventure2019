#include "CommandDrop.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using boost::lexical_cast;
using boost::bad_lexical_cast;





void CommandDrop::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {

    
    
    // Find character's location
    auto location = Command::characterManager.getCharacterLocation(username);
    
    
    // Room owns items that may be taken
    // Note: location.room actually means the id of the room
    auto room_id = location.room;
    
    
    // Keyword is the second element of the vector
    auto keyword = fullCommand.at(1);
    
    
    // Owner of the item
    debug::cout << "USER: " << username << "\n";
    auto character = Command::characterManager.characterDB.getCharacter(username);
    auto character_id = character.uid;
    debug::cout << "ID: " << character_id << "\n\n";
    
    
    // Search for identifiers of all items matching the keyword
    auto ids = Command::worldManager.items.search(character_id, keyword);
    auto items_found = ids.size();
    
    

    
    
    // No matching items found
    if (items_found == 0) {
        auto message = "Nothing found";
        
        Command::onlineUserManager.addMessageToUser(username, message);
        return;
    }
    
    
    // If search is ambiguous, an error message containing all matching
    // items is sent to the user so they can choose another unambigious
    // keyword, or select item to take by its identifier
    if (items_found != 1) {
        auto message = std::to_string(ids.size());
        // Choosing by id not available
        message     += " items match this keyword. Choose another keyword: \n\n";
        message     += Command::worldManager.items.detailsOfList(room_id, ids);
        
        Command::onlineUserManager.addMessageToUser(username, message);
        return;
    }
    
    
    // If search is not ambiguous, owner will be changed from
    // room_id to character_id
    auto item_id = ids[0];
    Command::worldManager.items.reassign(character_id, room_id, item_id);
    
    // Send message to user
    auto message = "You dropped " + keyword;
    Command::onlineUserManager.addMessageToUser(username, message);
    
    
    
    
    
    
    
}

















std::vector<std::string> CommandDrop::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: drop [object-in-inventory]
    //Format: drop [object-in-inventory] [object-index]
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
