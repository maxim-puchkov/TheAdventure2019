//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_ROOM_H
#define WEBSOCKETNETWORKING_ROOM_H


#include <string>
#include <vector>
#include <utility> //std::move (objects)
#include "Exit.h"
// #include "Character.h"
#include "LocationCoordinates.h"
#include <algorithm>
#include "auth.hpp"
// #include "NPC.h"


using auth::Authenticator;
using auth::Identifier;


class Room {
private:
    
    int roomId;
    std::string roomName;
    std::string roomDescription;
    std::vector<std::string> charactersInRoom;
    std::vector<std::string> NPCsInRoom;
    std::vector<Exit> exitsInRoom;
    
public:
    
    const Identifier container_id;
    
    Room(Identifier cid)
    : roomName("NO_ROOM_NAME"),
    roomDescription("NO_ROOM_DESCRIPTION"),
    container_id(cid)
    { }
    
    Room(std::string rName, std::string rDescription, Identifier cid)
    : roomName(std::move(rName)),
    roomDescription(std::move(rDescription)),
    container_id(cid)
    { }
    
    LocationCoordinates findExitLocation(const std::string& cardinalDirection) const;
    bool createExit(const std::string& exitName, const std::string& exitDescription,
                    const std::string& cardinalDirection, std::string areaID, int roomID);
    bool addCharacter(const std::string &userName);
    bool removeCharacter(const std::string &userName);


    std::string lookForName(const std::string &objName) const;

    std::string lookForExitName(const std::string &objName) const;
    const std::string lookCardinalDirection(const std::string &cardinalDirection) const;


    std::string listExits() const;
    int getRoomId();


    //getters
    std::string getName() const { return roomName; }
    std::string getDescription() const { return roomDescription; }
    const std::vector<std::string>& getUserNames() const { return charactersInRoom; }
    std::vector<Exit>& getExits() { return exitsInRoom; }
    int getRoomID(){return roomId;}
    //setters
    void setName(std::string newName) { roomName = newName; }
    void setDescription(std::string newDescription) { roomDescription = newDescription; }
    void setRoomID(int id){roomId = id;}

    //NPCs
    bool addNPC(const std::string &name);
    bool removeNPC(const std::string &name);
    std::vector<std::string>& getNPCs(){return NPCsInRoom;}
    void updateExits(int id, std::string name);




};




#endif //WEBSOCKETNETWORKING_ROOM_H
