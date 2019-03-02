//
// Created by john on 01/03/19.
//

#include "MiniGameLobby.h"

MiniGameLobby::MiniGameLobby() {}

void MiniGameLobby::createGame(const std::string& userName) {
    MiniGameMatch newGame{userName};
    this->gameList.push_back(newGame);
}

MiniGameMatch& MiniGameLobby::getMatchWithPlayer(const std::string& playerName) {
    for(auto& match : gameList){
        if (match.hasPlayer(playerName)){
            return match;
        }
    }
    return nullMatch;
}