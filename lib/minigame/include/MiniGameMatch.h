//
// Created by john on 01/03/19.
//

#ifndef ADVENTURE2019_MINIGAMEMATCH_H
#define ADVENTURE2019_MINIGAMEMATCH_H

#include <string>
#include <vector>
#include <algorithm>
#include "MoveValidator.h"

class MiniGameMatch {

public:
    MiniGameMatch();
    MiniGameMatch(const std::string& userName);

    bool hasPlayer(const std::string& playerName) const;
    bool hasSpectator(const std::string& playerName) const;
    bool isPlayersTurn(const std::string& playerName) const;
    bool makePlayerMove(const std::string& playerName, std::string& move);
    bool addPlayer(const std::string& playerName);
    void removePlayer(const std::string& playerName);
    unsigned int getCurrentPlayers() const;

    std::string display();

    std::string getAdminName() const;
    std::vector<std::string>& getPlayers();
    std::vector<std::string>& getSpectators();

    //MoveValidator& getGame() ;

private:
    std::vector<std::string> players;
    std::vector<std::string> spectators;

    MoveValidator game;
    std::string adminName;
    unsigned int currentPlayerTurn;

};


#endif //ADVENTURE2019_MINIGAMEMATCH_H
