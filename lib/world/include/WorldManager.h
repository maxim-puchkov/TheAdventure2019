//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDMANAGER_H
#define WEBSOCKETNETWORKING_WORLDMANAGER_H

#include <string>
#include <vector>
#include <memory>
#include <exception>
#include <cstdlib> //std::rand
#include "Area.h"
#include "Room.h"
#include "Character.h"
#include "LocationCoordinates.h"

class WorldManager {
private:
    std::vector<Area> areas;
public:
    WorldManager();
    void generateWorld();
    Room& findRoomByLocation(LocationCoordinates location);

    //commands
    bool kick(const std::string& characterName, LocationCoordinates location);
    bool spawn(const std::string& characterName, LocationCoordinates location);
    std::string listExits(LocationCoordinates location) ;
    std::string listPeople(const Character& character);
    const std::vector<std::string>& getUserNamesInRoom (LocationCoordinates location) ;
    const std::vector<std::string> getUserNamesInRange (LocationCoordinates location, unsigned int range) ;
    LocationCoordinates move(const std::string& characterName, LocationCoordinates location, const std::string& direction) ;
    std::string look(LocationCoordinates location) ;
    std::string look(LocationCoordinates location, std::string objName) ;
};




#endif //WEBSOCKETNETWORKING_WORLDMANAGER_H
