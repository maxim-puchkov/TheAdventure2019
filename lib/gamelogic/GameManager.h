//
// Created by john on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include "world/include/WorldManager.h"

class GameManager{

private:
    static GameManager* instance;
    GameManager();
    WorldManager *world;
	usermanager::User* getUser(const std::string userName) const;

public:
    static GameManager* getInstance();
    ~GameManager();
	std::string extractCommands(const std::string command) const;
	void heartbeat() const;
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H