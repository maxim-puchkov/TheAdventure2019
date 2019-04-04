#include "CommandExamine.h"
#include <boost/algorithm/string.hpp>

using internationalization::Internationalization;

void CommandExamine::executeInHeartbeat(const std::string& username, const std::vector<std::string>& fullCommand) {
	auto location = characterManager.getCharacterLocation(username);
    if(location.area == "") {
    	//should not reach here, report error
    	return;
    }

	if(fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::EXITS)){
	    onlineUserManager.addMessageToUser(username, (worldManager.listExits(location) + "\n"));
    }else if(fullCommand[1] == stringManager.getString(Internationalization::STRING_CODE::NPCS)){
        auto currentRoom = worldManager.findRoomByLocation(location);
        auto NPCs = currentRoom.getNPCs();
        std::string returnMessage = stringManager.getString(Internationalization::STRING_CODE::NPC_IN_ROOM);
        for(auto npc : NPCs) {
            returnMessage += "- " + npc;
            returnMessage += "\n";
        }
        onlineUserManager.addMessageToUser(username, returnMessage);
    }else{
	    onlineUserManager.addMessageToUser(username, (worldManager.look(location, fullCommand[1]) + "\n"));
    }
}

std::vector<std::string> CommandExamine::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: examine <object/username>
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);
    commandIsValid = (processedCommand.size() == 2);

    return processedCommand;
}
