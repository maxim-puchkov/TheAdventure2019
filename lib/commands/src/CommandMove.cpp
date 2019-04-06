#include "CommandMove.h"
#include <boost/algorithm/string.hpp>

void CommandMove::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
    if(combatManager.playerIsInCombat(username)){
        onlineUserManager.addMessageToUser(username, "Cannot do this while in combat.\n");
        return;
    }

    auto location = characterManager.getCharacterLocation(username);
    if(location.area == "") {
        //should not reach here, report error
        return;
    }
    
    auto newLocation = worldManager.move(username, location, fullCommand[1]);
    characterManager.changeCharacterLocation(username, newLocation);
    auto room = worldManager.findRoomByLocation(newLocation);
    std::stringstream answer;
    answer << "Current location: Area:" << newLocation.area << ", Room: " << room.getName() << "\n";
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