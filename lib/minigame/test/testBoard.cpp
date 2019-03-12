/**
 * Test's triangles
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MoveValidator.h"
#include "Board.h"

using std::string;

//first parameter is name of grouping, 2nd parameter is the name of the test
//Test's the pawns in the chess game
TEST(BoardTest,  pawn){

    MoveValidator move;
    std::string input = "a2,a3";

    bool isValid = move.readChessMove(input) ;
    EXPECT_EQ(isValid, true);

    //Move red pawn from a3 to a5 move is invalid cannot jump 2 squares
    input = "a3,a5";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid, false);

    //Move blue pawn in 'a' column down valid
    input = "a7,a6";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid, true);

    input = "a3,a4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid, true);

    input = "a4,a5";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid, true);

    //Invalid move pawns can only kill diagonally
    input = "a5,a6";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid, false);
   // move.getBoardView();


    input = "h7,h5";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);


    input = "h2,h4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    //Now move the attempt to move the pawns directly on top of each other, should be invalid.
    input = "h4,h5";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,!isValid);


    input = "h5,h4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,!isValid);

}

TEST(BoardTest, pawnDiagonal){

    MoveValidator move;
    //move.getBoardView();

    std::string input = "a2,a4";
    move.readChessMove(input);

    input = "b7,b5";
    move.readChessMove(input);

    //See if red can kill blue diagonally.
    input = "a4,b5";
    bool isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    //move.getBoardView();

    input = "a7,a6";
    move.readChessMove(input);

    //move.getBoardView();

    input = "b5,a6";
    isValid = move.readChessMove(input);

    EXPECT_EQ(isValid,true);

    //move.getBoardView();

    //Now testing the blue side
    input = "b2,b4";
    move.readChessMove(input);
    input = "c7,c5";
    move.readChessMove(input);
   // move.getBoardView();

    input = "c5,b4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true, isValid);
   // move.getBoardView();

   input = "c2,c3";
   move.readChessMove(input);

   //move.getBoardView();

   input = "b4,c3";
   isValid = move.readChessMove(input);
   EXPECT_EQ(true,isValid);

}

TEST(BoardTest,pawnDiagonalTwo){

    MoveValidator move;
    std::string input = "c2,c4";
    move.readChessMove(input);

    input = "d7,d5";
    move.readChessMove(input);

    // move.getBoardView();

    //Illegal move pawn cannot move in this direction.
    input = "d5,e4";
    bool isValid = move.readChessMove(input);
    //move.getBoardView();
    EXPECT_EQ(isValid,false);

    input = "d5,e6";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid,false);

}

//To see where the pieces are use move.getBoardView()
TEST(BoardTest, Rook){


    MoveValidator move;
    string input = "a8,a7";

    bool isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);

    input = "a7,a5";
    move.readChessMove(input);

    input = "a8,a6";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid,true);

    input = "a6,h6";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);


    input = "h6,h2";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid,true);

    //Now attempt to have rook attack piece behind it.
    input = "h2,f2";
    isValid = move.readChessMove(input);

    // move.getBoardView();
    EXPECT_EQ(false,isValid);

    //Now test if the red rook can "Illegaly go through the blue rook. If you want to see the board do move.getBoardView//
    input = "h1,h4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);

    input = "h2,g2";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);


    input = "h1,h2";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    input = "g7,g6";
    isValid = move.readChessMove(input);

    //Attempt to go through blue pawn
    input = "g2,g6";
    isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);



}

TEST(BoardTest, badInput){
    MoveValidator move;

    string input;
    bool isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);

    input = "adfjsfa,asdfjl234aefaf;j,2";
    isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);

    input = "a-1,a10";
    isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);

    input = ",";
    isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);

    //input = nullptr; This test actually fails and I don't know how to check a string for nullptr
    isValid = move.readChessMove(input);
    EXPECT_EQ(false,isValid);

}

TEST(BoardTest, knight){
    MoveValidator move;
    //TESTING ALL THE POSSIBLE MOVES OF THE KNIGHT

    string input = "b1,c3";
    bool isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    input = "c3,b1";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    input = "b1,a3";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    input = "a3,b1";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    //Duplicate move
    input = "b1,a3";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);


    input = "a3,c4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);

    input = "c4,e3";
    isValid = move.readChessMove(input);
    EXPECT_EQ(true,isValid);


    input = "e3,g4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid,true);
    //move.getBoardView();

    input = "g4,e3";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid,true);

    input = "e3,c4";
    isValid = move.readChessMove(input);
    EXPECT_EQ(isValid,true);

}

TEST(BoardTest, testBishop){

    //Code should have been tested this way to begin with, but too lazy to rewrite all the methods above.
    Board bishop;

    bishop.movePiece({1,1},{2,1});
    PieceUnit  tmp = bishop.requestUnit({2,1});
    EXPECT_EQ(tmp,PAWN);

    bishop.movePiece({0,2},{2,0});
    EXPECT_EQ(bishop.requestUnit({2,0}),BISHOP);


    bishop.movePiece({2,0},{7,4});
    EXPECT_EQ(bishop.requestUnit({2,0}), BISHOP);


    bishop.movePiece({2,0},{7,5});
    EXPECT_EQ(bishop.requestUnit({2,0}), BISHOP); //Move should have failed bishop cannot go through units.

    bishop.movePiece({2,0},{6,4});
    EXPECT_EQ(bishop.requestUnit({2,0}),NONE);


    bishop.movePiece({3,7},{2,6});
    EXPECT_EQ(bishop.requestUnit({2,6}),BISHOP);



}

TEST(BoardTest, testPromotionAndKillKing){

    Board board;

    board.movePiece({1,1},{3,1});
    board.movePiece({3,1},{4,1});
    board.movePiece({4,1},{5,1});
    board.movePiece({5,1},{6,2});
    board.movePiece({6,2},{7,3});

    EXPECT_EQ(board.requestUnit({7,3}), QUEEN );


    board.movePiece({6,4},{4,4});

    board.movePiece({4,4},{3,4});
    board.movePiece({3,4},{2,4});
    board.movePiece({2,4},{1,3});
    board.movePiece({1,3},{0,2});


    EXPECT_EQ(board.requestUnit({0,2}), QUEEN );



    board.movePiece({0,2},{0,3});

    EXPECT_EQ(board.getLastPieceKilled().getPieceUnit(), QUEEN);

    std::cout << board.getBoardView();
    board.movePiece({0,3},{0,4});

    std::cout << board.getBoardView();


    EXPECT_EQ(board.getLastPieceKilled().getPieceUnit(),KING);





}



// Queen is RookAndBishop combined so we don't really need to test, since we reuse function/method.