#ifndef ADVENTURE2019_MINIGAMELOBBY_H
#define ADVENTURE2019_MINIGAMELOBBY_H

#include <vector>
#include <string>
#include <tuple>
#include "MiniGameMatch.h"
//#include "TimeStamp.h"

class MiniGameLobby {

public:
    MiniGameLobby();

    MiniGameMatch& createGame(const std::string& userName);
    void deleteGame(const std::string& adminName);
    void createInvite(const std::string& inviterName, const std::string& invitedName);
    void clearStaleInvites();
    bool confirmInvite(const std::string& invitedName);
    void removeInvite(const std::string& eitherName);

    MiniGameMatch& getMatchWithPlayer(const std::string& playerName);

    std::string printGames() const;
    std::string printInvites() const;

    std::string spectate(const std::string &userName, const std::string &observingGame);


private:
    MiniGameMatch nullMatch{};
    std::vector<MiniGameMatch> gameList;
    std::vector<std::tuple<std::string, std::string, long>> pendingInvites; // {inviterName, invitedName, timestamp}

};


#endif
