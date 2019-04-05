#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "CharacterManager.h"
#include "AreaGenerator.h"

#include "GamePrefixHeader.pch"
#include "auth.hpp"


using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;
using auth::Authenticator;
using auth::Identifier;


class GameManager {
private:
    
    WorldManager world{};
    OnlineUserManager onlineUserManager{};
    CharacterManager characterManager{};
    
    std::unordered_map<std::string, std::unique_ptr<Command>> tableOfCommands;
    std::string extractKeyword(std::string& fullCommand);
    void createTableOfCommands();
    
public:
    
    GameManager();
    std::string extractCommands(const std::string& connectionID, std::string fullCommand);
    std::unique_ptr<std::unordered_map<std::string, std::string>> heartbeat();
    
};

#endif //GAMEMANAGER_H
