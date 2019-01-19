//
// Created by jordan on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_WORLDMANAGER_H
#define WEBSOCKETNETWORKING_WORLDMANAGER_H

#include "../include/Room.h"
#include "../../../usermanager/include/User.h"

class WorldManager {
private:
    Room worldRooms[10];
public:
    WorldManager();
    void generateWorld();
    int move(usermanager::User* character, short direction);
    std::string look(unsigned int roomID) const;
};





#endif //WEBSOCKETNETWORKING_WORLDMANAGER_H
