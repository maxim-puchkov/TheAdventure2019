//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDMANAGER_H
#define WEBSOCKETNETWORKING_WORLDMANAGER_H

#include <string>
#include <vector>
#include <cstdlib> //std::rand
#include "Area.h"
#include "Room.h"
#include "Character.h"

class WorldManager {
private:
    std::vector<Area> areas;
public:
    WorldManager();
    void generateWorld();
    LocationCoordinates move(Character* character, Exit::CardinalDirection direction) const;
    std::string look(Character* character) const;
};




#endif //WEBSOCKETNETWORKING_WORLDMANAGER_H
