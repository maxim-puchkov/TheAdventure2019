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
#include "MiniGameLobby.h"
#include "Avatar.h"
#include "LocationCoordinates.h"
#include "AvatarManager.h"


using usermanager::OnlineUserManager;
using avatarmanager::AvatarManager;

class GameManager{

private:
    WorldManager world;
    MiniGameLobby miniGameLobby;
    OnlineUserManager onlineUserManager{};
    AvatarManager avatarManager;
    user::User getUser(const std::string& userName);
    std::string getUserIDByUsername(const std::string& userName);
    Avatar& getAvatarByUsername(const std::string& userName);
    const int YELL_RANGE = 1;
    const int SAY_RANGE = 0;

    struct commandGuideline {
        std::string (GameManager::*promptReply)(const std::string&, const std::vector<std::string>&);
        std::string (GameManager::*heartbeatReply)(const std::string&, const std::vector<std::string>&);
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
    std::string commandStartGame(const std::string& username, const std::vector<std::string>& fullCommand);
    std::string commandGameMove(const std::string& username, const std::vector<std::string>& fullCommand);
    std::string commandSay(const std::string& username, const std::vector<std::string>& fullCommand);
    std::string commandYell(const std::string& username, const std::vector<std::string>& fullCommand);
    std::string commandTell(const std::string& usernameOfSpeaker, const std::vector<std::string>& fullCommand);
    std::string commandMove(const std::string& username, const std::vector<std::string>& fullCommand);
    std::string commandLook(const std::string& username, const std::vector<std::string>& fullCommand);
    std::string commandExamine(const std::string& username, const std::vector<std::string>& fullCommand); //can only examine users
    std::string commandError(const std::string& username, const std::vector<std::string>& fullCommand);
    
    bool commandIsValid(size_t commandPartsSize, size_t messagePartSize, commandGuideline guideline);
    void reassembleCommand(std::string fullCommand, std::vector<std::string>& commandParts, std::vector<std::string>& splitByColon);
    void createTableOfCommands();


public:
    GameManager();
    std::string extractCommands(const std::string& connectionID, const std::string& fullCommand);
    std::unique_ptr<std::unordered_map<std::string, std::string>> heartbeat();
};

#endif //WEBSOCKETNETWORKING_GAMEMANAGER_H
