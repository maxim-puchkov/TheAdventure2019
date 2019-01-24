//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDMANAGER_H
#define WEBSOCKETNETWORKING_WORLDMANAGER_H

#include <string>
#include <cstdlib> //std::rand
#include "../include/Room.h"
#include "../../character/include/Character.h"

class WorldManager {
private:
    Room worldRooms[10];
public:
    WorldManager();
    void generateWorld();
    bool move(Character* character, short direction);
    std::string look(LocationCoordinates location) const;
};





#endif //WEBSOCKETNETWORKING_WORLDMANAGER_H
