//
// Created by john on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include "WorldManager.h"
#include "AccountManager.h"

class GameManager{

private:
    WorldManager *world;
	user::User* getUser(const std::string userName) const;

public:
    GameManager();
	std::string extractCommands(const std::string connectionID, const std::string command) const;
	void heartbeat() const;
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H