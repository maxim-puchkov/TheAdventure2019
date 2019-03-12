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
std::string MoveValidator::drawBoard(){
    return gameBoard.drawBoard();
}

/**
 * Checks to see if the input is valid.
 * @param startPos - The position you are starting from
 * @param finishPos - The position you expect to finish at.
 */
bool MoveValidator::processChessMove(const ChessCoordinate &startPos, const ChessCoordinate &finishPos) {

    if(startPos.col <= -1 || startPos.row <= -1 || finishPos.col <= -1 || finishPos.row <= -1){
        std::cout << "Output outside of the chess board!\n";
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
std::string MoveValidator::helpMessage(){

    std::string msg = "Welcome to chess2019!. Some of the rules are modified from standard chess\n"
                      "such as checks/checkmates aren't declared, game ends when king is terminated, \n"
                      "you cannot execute the En passant maneuver, when you reach the end of the board \n"
                      "with a pawn your piece is promoted to a queen automatically. To input a move enter\n"
                      "the source coordinate followed by a , followed by another coordinate \n"
                      "EX. a2,a4  is move piece at column A, row 2 to column A row 4.\n"
                      "Coordinates are printed on board for reference.  ";

    return msg;
}


bool MoveValidator::isGameFinished() const {
    const Piece &a = gameBoard.getPieceKilled();
    if(a.getPieceUnit() == KING){
        return true;
    }
    return false;
}

//Should be called after isGameFinished.
std::string MoveValidator::gameOverMessage() {

    std::string stream = "";
    const Piece &piece = gameBoard.getPieceKilled();

    if(piece.getPieceUnit() != KING){
        stream = "King isn't dead!, try calling isGameFinished first";
    }
    else if( piece.getColor() == RED ){
        stream = "team lower case has won the game ";
    } else {
        stream = "team upper case has won the game ";
    }
    return stream;
}




/**
 * @param input - Takes in a chess move. First specify the location of a piece then specify the
 * end spot next. Example move "a2,b6"
 */
bool MoveValidator::readChessMove(std::string &input) {

    //HOW TO CHECK FOR NULLPTR? it fails the test i made

    boost::trim(input);

    std::vector<std::string> result;
    boost::split(result,input,boost::is_any_of(","));

    if(result.size() > 2  || result.at(0).size() != 2 || result.at(1).size() != 2 ){
        return false;
    }


    int sCol =  convertCharColToInt(result.at(0).at(0));
    int sRow = convertChessRowToInt(result.at(0).at(1));
    ChessCoordinate startPos{sRow,sCol};

    int finishPositionColumn = convertCharColToInt(result.at(1).at(0));
    int finishPositionRow = convertChessRowToInt(result.at(1).at(1));
    ChessCoordinate finishPos{ finishPositionRow,finishPositionColumn };



    return processChessMove( startPos, finishPos );
}


