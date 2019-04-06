#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "LocationCoordinates.h"
#include "CharacterManager.h"
#include "Internationalization.h"
#include "AreaGenerator.h"
#include "JsonParser.h"

#include "GamePrefixHeader.pch"


using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using internationalization::Internationalization;

class GameManager{

private:
    Internationalization stringManager{};
	JsonParser jsonParser{};
    WorldManager world{};
    OnlineUserManager onlineUserManager{};
    CharacterManager characterManager{};
    CombatManager combatManager{};

    std::unordered_map<std::string, std::unique_ptr<Command>> tableOfCommands;
    int heartBeatDuration = 50;

    std::string extractKeyword(std::string& fullCommand);
    void createTableOfCommands();


public:
    GameManager();
    std::string extractCommands(const std::string& connectionID, std::string fullCommand);
    std::unique_ptr<std::unordered_map<std::string, std::string>> heartbeat();
};

#endif //GAMEMANAGER_H
