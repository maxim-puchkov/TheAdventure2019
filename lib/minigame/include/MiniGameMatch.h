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
    bool makePlayerMove(const std::string& playerName, std::string& move);

    void display();

    std::string getAdminName() ;

    MoveValidator& getGame() ;

private:
    std::vector<std::string> players;
    std::vector<std::string> spectators;

    MoveValidator game;
    std::string adminName;

};


#endif //ADVENTURE2019_MINIGAMEMATCH_H
