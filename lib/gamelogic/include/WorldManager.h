#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H

#include <string>
#include <cstdlib> //std::rand
#include "Room.h"
#include "Character.h"

class WorldManager {

private:
    Room worldRooms [10];

public:
    WorldManager();
    unsigned int move(Character* character, short direction) const;
    std::string look(unsigned int roomID) const;

};

#endif
