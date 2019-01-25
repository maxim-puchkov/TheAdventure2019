//
// Created by john on 18/01/19.
//

#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include <string>
#include <cstdlib>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "world/include/WorldManager.h"
#include "../accountManager/include/AccountManager.h"
#include "../accountManager/include/User.h"
#include "character/include/Character.h"

class GameManager{

private:
    WorldManager world;
    Character *dummyCharacter;
	user::User *getUser(const std::string userName) const;

public:
    GameManager();
    static GameManager* getInstance();
    //~GameManager();
	std::string extractCommands(const std::string command) const;
	void heartbeat() const;
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H