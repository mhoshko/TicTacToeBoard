#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn(){
  if(turn == X) turn = O;
  else turn = X;
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location.
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/
Piece TicTacToeBoard::placePiece(int row, int column){
  Piece empty = getPiece(row, column);
  if(empty==Invalid) return Invalid;
  else if(empty == Blank){
    board[row][column]=turn;
    toggleTurn();
  }
  return getPiece(row, column);
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column){
  if((row<0 || row>2) && (column<0 || column>2)) return Invalid;
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/


Piece TicTacToeBoard::getWinner(){
  if(getLineWinner(0, 0, 0, 1, 0, 2)!=Invalid) return getPiece(0,0);
  if(getLineWinner(1, 0, 1, 1, 1, 2)!=Invalid) return getPiece(1,0);
  if(getLineWinner(2, 0, 2, 1, 2, 2)!=Invalid) return getPiece(2,0);

  if(getLineWinner(0, 0, 1, 1, 2, 2)!=Invalid) return getPiece(0,0);
  if(getLineWinner(0, 2, 1, 1, 2, 0)!=Invalid) return getPiece(0,2);

  if(getLineWinner(0, 0, 1, 0, 2, 0)!=Invalid) return getPiece(0,0);
  if(getLineWinner(0, 1, 1, 1, 2, 1)!=Invalid) return getPiece(0,1);
  if(getLineWinner(0, 2, 1, 2, 2, 2)!=Invalid) return getPiece(0,2);

  if(fullBoard()==False) return Invalid;
  else return Blank;
}

bool TicTacToeBoard::fullBoard(){
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      if(board[i][j] == Blank) return False;
  return True;
}


Piece TicTacToeBoard::getLineWinner(int coord1, int coord2, int coord3, int coord4, int coord5, int coord6){
  if(getPiece(coord1, coord2)== getPiece(coord3, coord4) && getPiece(coord1, coord2)== getPiece(coord5, coord6)){
    return getPiece(coord1, coord2);
  }else return Invalid;
}
