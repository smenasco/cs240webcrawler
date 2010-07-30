#ifndef GAMEBOARD_H
#define GAMEBOARD_H
/*
 *  GameBoard.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include "ChessPiece.h"
#include "Square.h"
#include <vector>

//a vector of vecotrs containings squares
//keeps track of the current state of the chess 
//board
class GameBoard {
public:
	//constructor and destructor
	GameBoard();
	~GameBoard();
	
	//getters to find squares and pieces on chess board
	Square * GetSquare(int row, int col);
	Square * GetSquare(BoardPosition pos);
	ChessPiece * GetPiece(int row, int col);
	ChessPiece * GetPiece(BoardPosition pos);
	//------------------------------------------
	
	//resets to a standard new chess board
	//does not set up any piecs
	void Reset();
	
	//empties the board vectors
	void Clear();
	
	//sets us new pieces for standard new game
	void NewBoard();
	
	//return the current board position of the king of arg color
	const BoardPosition FindMyKing(PieceColor color);
private:
	std::vector< std::vector<Square*> > board;
	void Init();
	
};

#endif