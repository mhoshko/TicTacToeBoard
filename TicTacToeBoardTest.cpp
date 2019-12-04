/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, placedX){
  TicTacToeBoard board;
	ASSERT_EQ(board.placePiece(1, 2), X);
}

TEST(TicTacToeBoardTest, checkTakenPlace){
  TicTacToeBoard board;
	board.placePiece(1,2);
	ASSERT_EQ(board.placePiece(1, 2), X);
}


TEST(TicTacToeBoardTest, starttoggle){
  TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(), O);
}


TEST(TicTacToeBoardTest, checkuserplacedafterswitch){
  TicTacToeBoard board;
  board.placePiece(1, 2);
	ASSERT_EQ(board.placePiece(2, 3), O);
}


TEST(TicTacToeBoardTest, nomoveswinner){
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getWinner(), 32);
}


TEST(TicTacToeBoardTest, winner){
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(1,0);
	board.placePiece(2,2);
	board.placePiece(2,0);
	ASSERT_EQ(board.getWinner(), X);
}


TEST(TicTacToeBoardTest, nowinnerfullboard){
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(2,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,1);
	board.placePiece(2,2);
	ASSERT_EQ(board.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, checkgetpieceinit){
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(0, 0), Blank);
}


TEST(TicTacToeBoardTest, checkgetpieceplaced){
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, checkgetpieceincorrectlyplaced){
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,0);
	ASSERT_EQ(board.getPiece(0, 0), X);
}

TEST(TicTacToeBoardTest, outofbounds){
	TicTacToeBoard board;
	ASSERT_EQ(board.getPiece(4,4), Invalid);
}

TEST(TicTacToeBoardTest, nowinner){
	TicTacToeBoard board;
	board.placePiece(0,0);
	ASSERT_EQ(board.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, twotoggles){
  TicTacToeBoard board;
  board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), X);
}

TEST(TicTacToeBoardTest, threetoggles){
  TicTacToeBoard board;
  board.toggleTurn();
  board.toggleTurn();
	ASSERT_EQ(board.toggleTurn(), O);
}
