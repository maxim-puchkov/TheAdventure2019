#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "CharacterManager.h"

#include "Command.h"
#include "CommandLogin.h"
#include "CommandLogout.h"
#include "CommandCreate.h"
#include "CommandHelp.h"
#include "CommandSay.h"
#include "CommandTell.h"
#include "CommandYell.h"
#include "CommandLook.h"
#include "CommandExamine.h"
#include "CommandMove.h"
#include "CommandCreateAva.h"
#include "CommandEditAva.h"
#include "CommandEditRoom.h"
#include "CommandCreateRoom.h"
#include "CommandUse.h"
#include "CommandEquip.h"
#include "CommandPickup.h"
#include "CommandDrop.h"
#include "CommandPut.h"
#include "CommandMinigame.h"
#include "CommandCombat.h"
#include "CommandAttack.h"
#include "CommandFlee.h"
#include "CommandCast.h"

using usermanager::OnlineUserManager;
using charactermanager::CharacterManager;

class GameManager{

private:
    WorldManager world{};
    OnlineUserManager onlineUserManager{};
    CharacterManager characterManager;
    std::unordered_map<std::string, std::unique_ptr<Command>> tableOfCommands;
    
    std::string extractKeyword(std::string& fullCommand);
    void createTableOfCommands();


public:
    GameManager();
    std::string extractCommands(const std::string& connectionID, std::string fullCommand);
    std::unique_ptr<std::unordered_map<std::string, std::string>> heartbeat();
};

#endif //GAMEMANAGER_H
