#ifndef ADVENTURE2019_MINIGAMELOBBY_H
#define ADVENTURE2019_MINIGAMELOBBY_H

#include <vector>
#include <string>
#include "MiniGameMatch.h"

class MiniGameLobby {

public:
    MiniGameLobby();

    void createGame(const std::string& userName);

    MiniGameMatch& getMatchWithPlayer(const std::string& playerName) ;

private:
    MiniGameMatch nullMatch{};
    std::vector<MiniGameMatch> gameList;

};


#endif
