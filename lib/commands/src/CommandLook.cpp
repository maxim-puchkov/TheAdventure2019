#include "CommandLook.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;
using boost::bad_lexical_cast;





void CommandLook::executeInHeartbeat(const std::string& userName, const std::vector<std::string>& fullCommand) {

	auto location = characterManager.getCharacterLocation(userName);


    if(location.area == -1) {
        //should not reach here, report error
        onlineUserManager.addMessageToUser(userName, "ERROR: this message should not print,\n"
                                                     "you need to create an avatar first!.\n"
                                                     "If this message prints w/an avatar something went wrong"
                                                     " invalid area for looking\n" );
        return;
    }

    auto room = worldManager.findRoomByLocation(location);
    const std::string &listOfExits = room.listExits();

    if(fullCommand.size() == 1){
        std::string allUsersInRoom = " ";
        for(const std::string &userA : room.getUserNames() ){
            allUsersInRoom.append(userA + ",\n");
        }

        onlineUserManager.addMessageToUser(userName, (listOfExits + "\n" + allUsersInRoom + worldManager.look(location) ));
        return;

    }

    /////////////////////////////////////////// If looking at a specific user then....
    //ROUGH code debug later

    std::string targetLookingAt = fullCommand.at(1);

    std::string result = room.lookForExitName(targetLookingAt);
    const std::string &charName = room.lookForName(targetLookingAt);
    if( !charName.empty() ){
       result.append( characterManager.getLongDescription( charName ) );
    }

    onlineUserManager.addMessageToUser(userName, result );

    //////////////////////////////////////////

}

std::vector<std::string> CommandLook::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {
    std::vector<std::string> processedCommand;

    //Format: look
    //Format: look [object/username]
    //format: look [object/username] [object/username-index]
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
        commandIsValid = (processedCommand.size() == 2 || processedCommand.size() == 1);
    }
   
    return processedCommand;
}