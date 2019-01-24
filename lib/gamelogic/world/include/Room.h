//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_ROOM_H
#define WEBSOCKETNETWORKING_ROOM_H


#include <string>
#include <vector>
//#include <algorithm> //std::any_of
#include <utility> //std::move (objects)
#include "../include/Exit.h"

//Messyish but we can fix later
//#include "../../character/headers/Character.h"
#include "../../../accountmanager/include/User.h"

class Room {

private:
    std::string roomName;
    std::string roomDescription;
    std::vector<user::User*> charactersInRoom;
    //std::vector<Item> itemsInRoom;
    std::vector<Exit> roomExits;

public:
    Room()
            : roomName("NO_ROOM_NAME"),
              roomDescription("NO_ROOM_DESCRIPTION")
    {}
    Room(std::string rName, std::string rDescription)
            : roomName(rName),
              roomDescription(rDescription)
    {}
    int move(user::User* character, short direction);
    bool createExit(std::string exitName, std::string exitDescription,
                    short cardinalDirection, int targetRoomID);
    bool addCharacter(user::User* character);
    bool removeCharacter(user::User* character);
    //getters
    std::string getName() const { return roomName; }
    std::string getDescription() const { return roomDescription; }
    //setters
    void setName(std::string newName) { roomName = newName; }
    void setDescription(std::string newDescription) { roomDescription = newDescription; }
};




#endif //WEBSOCKETNETWORKING_ROOM_H
