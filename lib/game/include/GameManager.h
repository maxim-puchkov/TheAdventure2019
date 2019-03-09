#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include <string>
#include <vector>
#include <exception>
#include <iostream>
#include <unordered_map>

#include "User.h"
#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "Avatar.h"
#include "LocationCoordinates.h"
#include "AvatarManager.h"

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

using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class GameManager{

private:
    WorldManager world;
    OnlineUserManager onlineUserManager{};
    AvatarManager avatarManager;
    std::unordered_map<std::string, std::unique_ptr<Command>> table;
    
    bool commandIsValid(size_t commandPartsSize, size_t messagePartSize);
    void reassembleCommand(std::string fullCommand, std::vector<std::string>& commandParts, std::vector<std::string>& splitByColon);
    void createTableOfCommands();


public:
    GameManager();
    std::string extractCommands(const std::string& connectionID, const std::string& fullCommand);
    std::unique_ptr<std::unordered_map<std::string, std::string>> heartbeat();
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H
