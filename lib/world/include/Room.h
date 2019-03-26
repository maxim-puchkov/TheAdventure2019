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
    int roomId = -1;
    std::string roomName;
    std::string roomDescription;
    std::vector<std::string> charactersInRoom;
    std::vector<Exit> exitsInRoom;

public:
    Room()
            : roomName("NO_ROOM_NAME"),
              roomDescription("NO_ROOM_DESCRIPTION")
    {}
    Room(std::string rName, std::string rDescription)
            : roomName(std::move(rName)),
              roomDescription(std::move(rDescription))
    {}
    LocationCoordinates findExitLocation(const std::string& cardinalDirection) const;
    bool createExit(const std::string& exitName, const std::string& exitDescription,
                    const std::string& cardinalDirection, int areaID, int roomID);
    bool addCharacter(const std::string &userName);
    bool removeCharacter(const std::string &userName);

    std::string lookForName(const std::string &objName) const;
    std::string lookForExitName(const std::string &objName) const;
    std::string listExits() const;
    void setRoomId(int id);
    int getRoomId();


    //getters
    std::string getName() const { return roomName; }
    std::string getDescription() const { return roomDescription; }
    const std::vector<std::string>& getUserNames() const { return charactersInRoom; }
    const std::vector<Exit>& getExits() const { return exitsInRoom; }
    //setters
    void setName(std::string newName) { roomName = newName; }
    void setDescription(std::string newDescription) { roomDescription = newDescription; }
};




#endif //WEBSOCKETNETWORKING_ROOM_H
