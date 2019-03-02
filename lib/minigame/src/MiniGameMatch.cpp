//
// Created by john on 01/03/19.
//


#include "MiniGameMatch.h"

MiniGameMatch::MiniGameMatch() {
    this->adminName = "null";
}

MiniGameMatch::MiniGameMatch(const std::string& userName) {
    this->adminName = userName;
    this->players.push_back(userName);
    MoveValidator newGame;
    this->game = newGame;
}

bool MiniGameMatch::hasPlayer(const std::string& playerName) const{
    if(players.empty()) return false;

    auto result = std::find(players.begin(), players.end(), playerName);

    return result != players.end();
}

bool MiniGameMatch::hasSpectator(const std::string& spectatorName) const{
    if(spectators.empty()) return false;

    auto result = std::find(spectators.begin(), spectators.end(),spectatorName);

    return result != spectators.end();
}

bool MiniGameMatch::makePlayerMove(const std::string& playerName, std::string& move){
    if(!hasPlayer(playerName)) return false;

    return game.readChessMove(move);
}

std::string MiniGameMatch::display(){
    return game.drawBoard();
}

MoveValidator& MiniGameMatch::getGame() {
    return this->game;
}

std::string MiniGameMatch::getAdminName() {
    return this->adminName;
}