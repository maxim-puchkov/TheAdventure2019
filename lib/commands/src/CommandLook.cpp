#include "CommandLook.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
using boost::lexical_cast;
using boost::bad_lexical_cast;




void CommandLook::executeInHeartbeat(const std::string& userName, const std::vector<std::string>& fullCommand) {
    auto location = characterManager.getCharacterLocation(userName);
    if (location.area == "") {
        //should not reach here, report error
        onlineUserManager.addMessageToUser(userName, "ERROR: this message should not print,\n"
                                                     "you need to create an avatar first!.\n"
                                                     "If this message prints w/an avatar something went wrong"
                                                     " invalid area for looking\n");
        return;
    }


    auto room = worldManager.findRoomByLocation(location);
    const std::string &listOfExits = room.listExits();

    if (fullCommand.size() == 1) {
        std::string allUsersInRoom = " Users in room are : \n";
        for (const std::string &userA : room.getUserNames()) {
            allUsersInRoom.append(userA + ",\n");
        }
        onlineUserManager.addMessageToUser(userName, ("\n" + listOfExits + "\n" + allUsersInRoom + "\n" +
                                                      worldManager.look(location) + "\n"));
        return;
    } else if (fullCommand.at(1) == "exits") {
        onlineUserManager.addMessageToUser(userName, (worldManager.listExits(location) + "\n"));
        return;
    }else if(fullCommand.at(1) == "world"){
        //use for admin. look world => output the list of room
        //TODO: for some reasons the server does not print the full string
        //      if the string is too long. Only print the second half of the string.
        auto role = onlineUserManager.getUserRole(userName);
        switch(role) {
            case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND: {
                std::cout << "Please log in again.\n";
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_NORMAL_USER: {
                //don't let normal user know that this syntax exists
                std::cout <<  "Wrong command syntax. Please enter \"help\" to see the syntax.\n";
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN: {
                auto location = characterManager.getCharacterLocation(userName);
                auto resultMessage = worldManager.worldDetail(location);
                onlineUserManager.addMessageToUser(userName, resultMessage);
            }
            case usermanager::OnlineUserManager::USER_CODE::INVALID_USERNAME: {}
            case usermanager::OnlineUserManager::USER_CODE::ACCOUNT_CREATED: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_UPDATED: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_DELETED: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_OUT: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_NOT_ONLINE: {}
        }
        return;
    }


    //Return's "empty string if invalid direction/fails"
    const std::string& roomDescription = room.lookCardinalDirection(fullCommand.at(1));
    if( !roomDescription.empty() ) {
        onlineUserManager.addMessageToUser(userName, roomDescription + "\n");
        //If a user happens to have the same name as a cardinalDirection send all the output to the user
    }


    std::string appendedCommand;
    for(int i = 1; i < fullCommand.size(); i++){
        appendedCommand.append( fullCommand.at(i) + " " );
    }
    boost::trim(appendedCommand);

    //For looking at a specific user
    const std::string& characterDescription = ( characterManager.getLongDescription(appendedCommand) ); // This line causes the crash
    onlineUserManager.addMessageToUser(userName, characterDescription );




}

std::vector<std::string> CommandLook::reassembleCommand(std::string& fullCommand, bool& commandIsValid) {

    std::vector<std::string> processedCommand;
    //Format: look
    //Format: look [object/username]
    //format: look [object/username] [object/username-index]
    boost::trim_if(fullCommand, boost::is_any_of(" \t"));

    //split by " " and compress all long spaces
    boost::split(processedCommand, fullCommand, boost::is_any_of(" \t"), boost::token_compress_on);

   /* if(processedCommand.size() == 3) {
        //check if [object-index] is a positive number
        try {
            commandIsValid = (lexical_cast<int>(processedCommand[2]) > 0);
        } catch(const bad_lexical_cast &) {
            commandIsValid = false;
        }

    } else { */
        commandIsValid = (processedCommand.size() >= 1 && processedCommand.size() <= 5);
    // }
   
    return processedCommand;
}