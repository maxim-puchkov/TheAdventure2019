//
// Created by john on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "world/include/WorldManager.h"
#include "../accountManager/include/AccountManager.h"
#include "../accountManager/include/User.h"
#include "character/include/Character.h"

class GameManager{

private:
    static GameManager* instance;
    GameManager();
    WorldManager *world;
    Character *dummyCharacter;
	user::User *getUser(const std::string userName) const;

public:
    static GameManager* getInstance();
    //~GameManager();
	std::string extractCommands(const std::string command) const;
	void heartbeat() const;
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H