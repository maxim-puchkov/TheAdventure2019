#include "CommandLook.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "ItemController.h"

using boost::lexical_cast;
using boost::bad_lexical_cast;
#include "Item.h"
#include <string.h>


void CommandLook::generalLook(const std::string &userName) const {

    auto location = characterManager.getCharacterLocation(userName);
    auto room = worldManager.findRoomByLocation(location);
    const std::string &listOfExits = room.listExits();

    std::string allUsersInRoom = stringManager.getString(Internationalization::STRING_CODE::USERS_IN_ROOM_ARE);
    for (const std::string &userA : room.getUserNames()) {
        allUsersInRoom.append( characterManager.getShortDescription(userA) );
    }

    allUsersInRoom.append(" NPCs are : \n");
    for (const std::string &npc : room.getNPCs() ) {
        allUsersInRoom.append( characterManager.getShortDescription(npc) );
    }

    onlineUserManager.addMessageToUser(userName, ("\n" + listOfExits + "\n" + allUsersInRoom + "\n" +
                                                  worldManager.look(location)  +   "\n"));

    
    const auto items = worldManager.items;
    const auto &vectorItems= items.contentsOf(location.room); //return a vector of id's and keywords
    std::string allItems;
    for(const auto &iter : vectorItems){
        const auto &itemRef = items.lookup(room.getRoomId(), iter.id );
        allItems.append(itemRef.getIdAndBrief() + "\n");
    }

    allItems.append("Room keywords : \n\t");
    for(const auto &iter : room.getExtendedKeyword()){
        allItems.append(iter + ", ");
    }
    allItems.append("\n");

    onlineUserManager.addMessageToUser(userName, allItems);
    
}



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


    //looking without an argument will look at the room itself and present the name and
    // description of the room as well as a short description of the characters, objects,
    // and cardinal/ordinal/vertical exits within the room.
    //A room may have special keywords that when looked at provide deeper description.
    auto room = worldManager.findRoomByLocation(location);
    std::cout << room.getName() << "\n";
//    const std::string &listOfExits = room.listExits();

    if (fullCommand.size() == 1) {
        generalLook(userName);
        return;
    } else if (fullCommand.at(1) == stringManager.getString(Internationalization::STRING_CODE::EXITS)) {
        onlineUserManager.addMessageToUser(userName, (worldManager.listExits(location) + "\n"));
        return;
    } else if(fullCommand.at(1) == stringManager.getString(Internationalization::STRING_CODE::KEYWORD)){

        bool itemFound = true;
        if(fullCommand.size() == 2){
            onlineUserManager.addMessageToUser(
                userName, 
                stringManager.getString(Internationalization::STRING_CODE::NO_KEYWORD_ENTERED)
            );
            return;
        }


       const auto &keyWordList = worldManager.items.search(room.getRoomID(),fullCommand.at(2));
       if(keyWordList.empty()){
           itemFound = false;
       } else {
           stringstream ostream;
           ostream << stringManager.getString(Internationalization::STRING_CODE::ITEMS_WITH_KEYWORD)
                   << fullCommand.at(2) << " \n";
           for (const items::ItemIdentifier &iter : keyWordList) {
               ostream << iter << "\n";
           }
           onlineUserManager.addMessageToUser(userName, ostream.str());
       }

       //Room Keywords

       const auto &roomKeyWords =room.getExtendedKeyword();
       const auto &target = std::find(roomKeyWords.begin(),roomKeyWords.end(), fullCommand.at(2));

       if(target!=roomKeyWords.end()){
           onlineUserManager.addMessageToUser(userName, (*target) + " " + room.getExtendedDesc());
       }

       if(!itemFound){
           onlineUserManager.addMessageToUser(
               userName, 
               stringManager.getString(Internationalization::STRING_CODE::NO_ITEMS_WITH_KEYWORD) 
            );
       }



        return;

    } else if (fullCommand.at(1) == "item"){
        std::string detailedItem;

        if(fullCommand.size() == 2){
            onlineUserManager.addMessageToUser(
                userName, 
                stringManager.getString(Internationalization::STRING_CODE::NO_ITEM_LOOKUP)
            );
            return;
        }

        try {
            int itemId = std::stoi(fullCommand.at(2));
            bool exist = worldManager.items.exists(room.getRoomID(), itemId);
            if(exist){
                const auto &item = worldManager.items.lookup(room.getRoomID(), itemId);
                onlineUserManager.addMessageToUser(userName,item.description.full() + "\n");
            } else {
                onlineUserManager.addMessageToUser(userName, " Item specified doesn't exist \n ");
            }
        }catch (const std::exception &e){
            onlineUserManager.addMessageToUser(userName, "Invalid item id! (not a number) \n");
        }


        return;
    } else if(fullCommand.at(1) == "world"){
        //use for admin. look world => output the list of room
        //TODO: for some reasons the server does not print the full string
        //      if the string is too long. Only print the second half of the string.
        auto role = onlineUserManager.getUserRole(userName);
        switch(role) {
            case usermanager::OnlineUserManager::USER_CODE::USER_NOT_FOUND: {
                std::cout << stringManager.getString(Internationalization::STRING_CODE::PLEASE_LOG_IN_AGAIN);
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_NORMAL_USER: {
                //don't let normal user know that this syntax exists
                std::cout <<  (
                    stringManager.getString(Internationalization::STRING_CODE::WRONG_COMMAND_SYNTAX), 
                    stringManager.getString(Internationalization::STRING_CODE::PLEASE_ENTER_HELP_SYNTAX)
                );
            }
            case usermanager::OnlineUserManager::USER_CODE::USER_ADMIN: {
                auto location = characterManager.getCharacterLocation(userName);
                auto resultMessage = worldManager.worldDetail(location);
                onlineUserManager.addMessageToUser(userName, resultMessage);
            }
            /* Someone else wrote this code... Not sure what I should do with it so, commented it out
            case usermanager::OnlineUserManager::USER_CODE::INVALID_USERNAME: {}
            case usermanager::OnlineUserManager::USER_CODE::ACCOUNT_CREATED: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_UPDATED: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_DELETED: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_OUT: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_LOGGED_IN: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_ALREADY_LOGGED_IN: {}
            case usermanager::OnlineUserManager::USER_CODE::USER_NOT_ONLINE: {}
            */
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
    for(unsigned int i = 1; i < fullCommand.size(); i++){
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
