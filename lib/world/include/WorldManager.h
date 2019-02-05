//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDMANAGER_H
#define WEBSOCKETNETWORKING_WORLDMANAGER_H

#include <string>
#include <vector>
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
    Room findRoomByLocation(LocationCoordinates location) const;

    //commands
    bool kick(Character* character);
    bool spawn(Character* character, LocationCoordinates location);
    std::string say (Character* character, std::string message) const;
    LocationCoordinates move(Character* character, const std::string& direction) const;
    std::string look(Character* character) const;
    std::string look(Character* character, std::string objName) const;
};




#endif //WEBSOCKETNETWORKING_WORLDMANAGER_H
