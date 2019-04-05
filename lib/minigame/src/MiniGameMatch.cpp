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

    this->game = MoveValidator(userName);
    game.setPlayerOne(userName);  // for cautios
}

MiniGameMatch::MiniGameMatch(const std::string& player1Name, const std::string& player2Name) {
    this->adminName = player1Name;
    this->players.push_back(player1Name);
    this->players.push_back(player2Name);

    this->currentPlayerTurn = 0;

    this->game = MoveValidator{player1Name,player2Name};
    game.setPlayerOne(player1Name);
    game.setPlayerTwo(player2Name);
}

bool MiniGameMatch::hasPlayer(const std::string& playerName) const{
    auto result = std::find(players.begin(), players.end(), playerName);
    return result != players.end();
}

bool MiniGameMatch::hasSpectator(const std::string& spectatorName) const{
    auto result = std::find(spectators.begin(), spectators.end(), spectatorName);
    return result != spectators.end();
}

//
bool MiniGameMatch::addSpectator(const std::string &userName) {
    if(hasPlayer(userName)){
        return false;
    }
    spectators.push_back(userName);
    return true;
}




bool MiniGameMatch::isPlayersTurn(const std::string& playerName) const{
    return players.at(currentPlayerTurn) == playerName;
}

bool MiniGameMatch::makePlayerMove(const std::string& playerName, std::string& moveFrom, std::string moveTo){
    if(!isPlayersTurn(playerName)) {
        return false;
    }

    bool moveResult = game.readChessMove(moveFrom,moveTo,playerName);
    if(moveResult == true) {
        currentPlayerTurn = (currentPlayerTurn + 1) % players.size();
    }
    return moveResult;

}

bool MiniGameMatch::addPlayer(const std::string& playerName){
    unsigned int maxPlayers = 2; //get this from Game.getMaxPlayers()
    if(players.size() >= maxPlayers) {
        return false;
    }
    players.push_back(playerName);
    game.setPlayerTwo(playerName);
    return true;
}

void MiniGameMatch::removePlayer(const std::string& playerName){
    players.erase(std::remove_if(players.begin(), players.end(),
                                        [&playerName](std::string& name){return name == playerName;}),
                         players.end());
}


void MiniGameMatch::removeSpectator(const std::string &spectatorName) {
    spectators.erase(std::remove_if(spectators.begin(), spectators.end(),
                                 [&spectatorName](const auto &iter){return iter == spectatorName;}),
                  spectators.end());
}


unsigned long MiniGameMatch::getCurrentPlayers() const{
    return players.size();
}

const std::string MiniGameMatch::display() const {
    return game.getBoardView();
}

bool MiniGameMatch::isGameFinished() const {
    return game.isGameFinished();
}

std::string MiniGameMatch::getWinMessage() const {
    return game.gameOverMessage();
}

//A "reversed" display for player 2.
const std::string MiniGameMatch::reverseDisplay() const {
    return game.getReverseBoardView();
}

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

const std::string& MiniGameMatch::getCurrentPlayerTurn() const {
    return players.at(currentPlayerTurn);
}


