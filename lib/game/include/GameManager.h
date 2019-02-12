#ifndef WEBSOCKETNETWORKING_GAMEMANAGER_H
#define WEBSOCKETNETWORKING_GAMEMANAGER_H

#include <string>
#include <vector>
#include <exception>
#include <iostream>
#include <unordered_map>

#include <memory>
#include "User.h"
#include "OnlineUserManager.h"
#include "WorldManager.h"
#include "Avatar.h"
#include "LocationCoordinates.h"


using usermanager::OnlineUserManager;

class GameManager{

private:
    WorldManager world;
    OnlineUserManager onlineUserManager{};
    user::User getUser(const std::string& userName);
    std::string getUserIDByUsername(const std::string& userName);
    Avatar& getAvatarByUsername(const std::string& userName);
    const int YELL_RANGE = 1;

    struct commandGuideline {
        std::string (GameManager::*promptReply)(const std::string&, const std::vector<std::string>&);
        std::string (GameManager::*heartbeatReply)(Avatar&, const std::vector<std::string>&);
        size_t commandPartArgCount;
        size_t messagePartArgCount;
        std::string helpText;
    };
    std::unordered_map<std::string, commandGuideline> tableOfCommands;

    //promptReply functions
    std::string commandLogin(const std::string& connectionID, const std::vector<std::string>& fullCommand);
    std::string commandLogout(const std::string& connectionID, const std::vector<std::string>& fullCommand);
    std::string commandCreate(const std::string& connectionID, const std::vector<std::string>& fullCommand);
    std::string commandAddToActionList(const std::string& connectionID, const std::vector<std::string>& fullCommand);
    std::string commandHelp(const std::string& connectionID, const std::vector<std::string>& fullCommand);
    
    //heartbeatReply functions
    std::string commandSay(Avatar& avatar, const std::vector<std::string>& fullCommand);
    std::string commandYell(Avatar& avatar, const std::vector<std::string>& fullCommand);
    std::string commandTell(Avatar& avatar, const std::vector<std::string>& fullCommand);
    std::string commandMove(Avatar& avatar, const std::vector<std::string>& fullCommand);
    std::string commandLook(Avatar& avatar, const std::vector<std::string>& fullCommand);
    std::string commandExamine(Avatar& avatar, const std::vector<std::string>& fullCommand); //can only examine users
    std::string commandError(Avatar& avatar, const std::vector<std::string>& fullCommand);
    
    bool commandIsValid(size_t commandPartsSize, size_t messagePartSize, commandGuideline guideline);
    void reassembleCommand(std::string fullCommand, std::vector<std::string>& commandParts, std::vector<std::string>& splitByColon);
    void createTableOfCommands();


public:
    GameManager();
    std::string extractCommands(const std::string& connectionID, const std::string& fullCommand);
    std::unique_ptr<std::unordered_map<std::string, std::string>> heartbeat();
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H
