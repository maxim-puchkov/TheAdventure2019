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

class Room {

private:
    std::string roomName;
    std::string roomDescription;
    std::vector<Character*> charactersInRoom;
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
    bool addCharacter(Character* character);
    bool removeCharacter(Character* character);
    std::string lookForName(std::string objName) const;
    //getters
    std::string getName() const { return roomName; }
    std::string getDescription() const { return roomDescription; }
    //setters
    void setName(std::string newName) { roomName = newName; }
    void setDescription(std::string newDescription) { roomDescription = newDescription; }
};




#endif //WEBSOCKETNETWORKING_ROOM_H
