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
    this->currentPlayerTurn = 0;


    MoveValidator newGame;
    this->game = newGame;
    newGame.setPlayerOne(userName);

}

MiniGameMatch::MiniGameMatch(const std::string& player1Name, const std::string& player2Name) {
    this->adminName = player1Name;
    this->players.push_back(player1Name);
    this->players.push_back(player2Name);
    this->currentPlayerTurn = 0;
    MoveValidator newGame;
    newGame.setPlayerOne(player1Name);
    newGame.setPlayerTwo(player2Name);
    this->game = newGame;
}


bool MiniGameMatch::hasPlayer(const std::string& playerName) const{
    auto result = std::find(players.begin(), players.end(), playerName);
    return result != players.end();
}

bool MiniGameMatch::hasSpectator(const std::string& spectatorName) const{
    auto result = std::find(spectators.begin(), spectators.end(), spectatorName);
    return result != spectators.end();
}

bool MiniGameMatch::isPlayersTurn(const std::string& playerName) const{
    return players.at(currentPlayerTurn) == playerName;
}

bool MiniGameMatch::makePlayerMove(const std::string& playerName, std::string& moveFrom, std::string moveTo){

    if(!isPlayersTurn(playerName)) {
        return false;
    }

    currentPlayerTurn = (currentPlayerTurn + 1) % players.size();
    return game.readChessMove(moveFrom, moveTo, playerName);

}

bool MiniGameMatch::addPlayer(const std::string& playerName){
    int maxPlayers = 2; //get this from Game.getMaxPlayers()
    if(players.size() >= maxPlayers) {
        return false;
    }
    players.push_back(playerName);
    return true;
}

void MiniGameMatch::removePlayer(const std::string& playerName){
    players.erase(std::remove_if(players.begin(), players.end(),
                                        [&playerName](std::string& name){return name == playerName;}),
                         players.end());
}


unsigned long MiniGameMatch::getCurrentPlayers() const{
    return players.size();
}

std::string MiniGameMatch::display(){
    return game.getBoardView();
}

/*MoveValidator& MiniGameMatch::getGame() {
    return this->game;
}*/


MoveValidator& MiniGameMatch::getGame() {
    return this->game;
}

std::string MiniGameMatch::getAdminName() const {
    return this->adminName;
}

std::vector<std::string>& MiniGameMatch::getPlayers(){
    return players;
}
std::vector<std::string>& MiniGameMatch::getSpectators(){
    return spectators;
}