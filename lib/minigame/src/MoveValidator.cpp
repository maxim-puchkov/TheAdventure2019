//
// Created by jordanhoang on 12/02/19.
//

#include "MoveValidator.h"
#include <boost/algorithm/string.hpp>
#include <iostream>

/**
 * Converts a column to a integer Ex. the move a2 will convert the 'a' into a 0
 */
int MoveValidator::convertCharColToInt(char input){

    input = std::tolower(input);

   // std::cout << "input is " << input << "\n";
    switch(input){
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
    }

    return -1;
}

/**
 * @param input
 * @return The int for the vector to handle.
 */
int MoveValidator::convertChessRowToInt(char input){
    int result = input - '0';
    if(result < 0 || result > 8){
        return -1;
    }
    return result - 1;
}

/**
 *
 * @return A string that you can use to draw the board
 */
const std::string MoveValidator::getBoardView() const {
    return  gameBoard.getBoardView();
}

const std::string MoveValidator::getReverseBoardView() const{
    return gameBoard.getReverseBoardView();
}


/**
 * Checks to see if the input is valid.
 * @param startPos - The position you are starting from
 * @param finishPos - The position you expect to finish at.
 */
bool MoveValidator::processChessMove(const ChessCoordinate &startPos, const ChessCoordinate &finishPos) {

    if(startPos.col <= -1 || startPos.row <= -1 || finishPos.col <= -1 || finishPos.row <= -1){
        return false;
    }

    if(startPos.col >= 8 || startPos.row >= 8 || finishPos.row >= 8 || finishPos.col >= 8){
        return false;
    }

    return  gameBoard.movePiece(startPos, finishPos);
}


/**
 * @return A message on how to play the game
 */
std::string MoveValidator::helpMessage() const{

    std::string msg = stringManager.getString(Internationalization::STRING_CODE::MINIGAME_CHESS_WELCOME_MESSAGE);

    return std::move(msg);
}



bool MoveValidator::isGameFinished() const {
    const Piece &a = gameBoard.getLastPieceKilled();
    if(a.getPieceUnit() == KING){
        return true;
    }
    return false;
}

//Should be called after isGameFinished.
std::string MoveValidator::gameOverMessage() const {

    std::string stream = "";
    const Piece &piece = gameBoard.getLastPieceKilled();

    if(piece.getPieceUnit() != KING){
        stream = stringManager.getString(Internationalization::STRING_CODE::MINIGAME_CHESS_KING_NOT_DEAD);
    }
    else if( piece.getColor() == RED_LOWERCASE ){
        stream = stringManager.getString(Internationalization::STRING_CODE::MINIGAME_CHESS_TEAM_LOWER_WON);
    } else {
        stream = stringManager.getString(Internationalization::STRING_CODE::MINIGAME_CHESS_TEAM_UPPER_WON);
    }
    return std::move(stream);
}



void MoveValidator::initializeSide(const std::string &playerOne, const std::string &playerTwo) {

    this->playerOne.playerName  = playerOne;
    this->playerOne.playerColor = RED_LOWERCASE;

    this->playerTwo.playerName  = playerTwo;
    this->playerTwo.playerColor = BLUE_UPPERCASE;

}

void MoveValidator::setPlayerOne(const std::string &playerOne) {

    this->playerOne.playerName  = playerOne;
    this->playerOne.playerColor = RED_LOWERCASE;

}

void MoveValidator::setPlayerTwo(const std::string &playerTwo) {

    this->playerTwo.playerName = playerTwo;
    this->playerTwo.playerColor = BLUE_UPPERCASE;

}


//Checks to see if a red player doesn't attempt to move a piece that doesn't belong to them.
bool MoveValidator::validatePlayer(const std::string &playerName, const Color &color) const {

    if(playerOne.playerName == playerName){
        return (playerOne.playerColor == color);
    }
    if(playerTwo.playerName == playerName){
        return (playerTwo.playerColor == color);
    }

    static_assert(-1 && "No playerId matches the one assigned to this game???? you shouldn't see this message");
    return false;
}



bool MoveValidator::readMoveValidator(vector<std::string> &result, ChessCoordinate &start, ChessCoordinate &finish) {

    if(result.size() > 2  || result.at(0).size() != 2 || result.at(1).size() != 2 ){
        return false;
    }


    int sCol =  convertCharColToInt(result.at(0).at(0));
    int sRow = convertChessRowToInt(result.at(0).at(1));
    if( sCol == -1 || sRow == -1){
        return false;
    }

    start.row = sRow;
    start.col = sCol;

    int finishPositionColumn = convertCharColToInt(result.at(1).at(0));
    int finishPositionRow = convertChessRowToInt(result.at(1).at(1));
    if(finishPositionColumn == -1 || finishPositionRow == -1){
        return false;
    }

    finish.row = finishPositionRow;
    finish.col = finishPositionColumn;


    if(start.col <= -1 || start.row <= -1){
        return false;
    }

    if(finish.col <= -1 || finish.row <= -1){
        return false;
    }

    return true;
}


/**
 * @param input - Takes in a chess move. First specify the location of a piece then specify the
 * end spot next.
 *
 */
bool MoveValidator::readChessMove(std::string &moveFrom, std::string &moveTo, const std::string &player) {

    std::vector<std::string> result;
    result.push_back(moveFrom);
    result.push_back(moveTo);
    ChessCoordinate start{-1,-1};
    ChessCoordinate finish{-1,-1};

    if(!readMoveValidator(result,start,finish)){
        return false;
    }


    const Color &pieceColor = gameBoard.requestPiece(start).getColor();
    if( !validatePlayer(player, pieceColor) ) {
        return false ;
    }

    return processChessMove( start, finish );
}


/**
 * Move's piece regardless of color, left here for test class.
 * @param moveFrom - ChessCoordinate you are from
 * @param moveTo   - ChessCoordinate you are moving to.
 */
bool MoveValidator::readChessMove(std::string &moveFrom, std::string &moveTo) {

    std::vector<std::string> result;
    result.push_back(moveFrom);
    result.push_back(moveTo);

    ChessCoordinate start{-1,-1};
    ChessCoordinate finish{-1,-1};

    if(!readMoveValidator(result,start,finish)){
        return false;
    }

    return processChessMove( start, finish );

}

MoveValidator::MoveValidator(const std::string &playerOne) {
    this->playerOne.playerName = playerOne;
    this->playerOne.playerColor = RED_LOWERCASE;

}

MoveValidator::MoveValidator(const std::string &playerOne, const std::string &playerTwo) {

    this->playerOne.playerName = playerOne;
    this->playerOne.playerColor = RED_LOWERCASE;

    this->playerTwo.playerName = playerTwo;
    this->playerTwo.playerColor = BLUE_UPPERCASE;
}

MoveValidator::MoveValidator() {
    this->gameBoard = gameBoard;
}
