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
	ASSERT_EQ(board.placePiece(1, 2), X);
}


TEST(TicTacToeBoardTest, starttoggle){
  TicTacToeBoard board;
	ASSERT_EQ(board.toggleTurn(), O);
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
