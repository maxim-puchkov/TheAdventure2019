//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_ROOM_H
#define WEBSOCKETNETWORKING_ROOM_H


#include <string>
#include <vector>
#include <utility> //std::move (objects)
#include "Exit.h"
#include "Character.h"
#include "LocationCoordinates.h"
#include <algorithm>


class Room {

private:
    std::string roomName;
    std::string roomDescription;
    std::vector<std::string> charactersInRoom;
    //std::vector<Item> itemsInRoom;
    std::vector<Exit> exitsInRoom;

public:
    Room()
            : roomName("NO_ROOM_NAME"),
              roomDescription("NO_ROOM_DESCRIPTION")
    {}
    Room(std::string rName, std::string rDescription)
            : roomName(rName),
              roomDescription(rDescription)
    {}
    LocationCoordinates findExitLocation(Exit::CardinalDirection cardinalDirection) const;
    bool createExit(std::string exitName, std::string exitDescription,
                    Exit::CardinalDirection cardinalDirection, int areaID, int roomID);
    bool addCharacter(const std::string &character);
    bool removeCharacter(const std::string &userName);


    std::string lookForName(const std::string &objName) const;
    std::string lookRoomName(const std::string &objName) const;


    //getters
    std::string getName() const { return roomName; }
    std::string getDescription() const { return roomDescription; }
    //setters
    void setName(std::string newName) { roomName = newName; }
    void setDescription(std::string newDescription) { roomDescription = newDescription; }
};




#endif //WEBSOCKETNETWORKING_ROOM_H
