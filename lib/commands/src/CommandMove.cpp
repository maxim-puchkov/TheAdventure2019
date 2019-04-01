#include "CommandMove.h"
#include <boost/algorithm/string.hpp>

using internationalization::Internationalization;

void CommandMove::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    auto location = characterManager.getCharacterLocation(username);
    if(location.area == -1) {
        //should not reach here, report error
        return;
    }
    
    auto newLocation = worldManager.move(username, location, fullCommand[1]);
    characterManager.changeCharacterLocation(username, newLocation);
    
    std::stringstream answer;
    answer << stringManager.getString(Internationalization::STRING_CODE::CURRENT_LOCATION);
    answer << stringManager.getString(Internationalization::STRING_CODE::AREA) << ": " << newLocation.area;
    answer << " ";
    answer << stringManager.getString(Internationalization::STRING_CODE::ROOM) << ": " << newLocation.room;
    answer << "\n";
    
    onlineUserManager.addMessageToUser(username, answer.str());
}

std::vector<std::string> CommandMove::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: move [direction]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 2);
   
    return processedCommand;
}