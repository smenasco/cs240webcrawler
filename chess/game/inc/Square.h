#ifndef SQUARE_H
#define SQUARE_H

/*
 *  Square.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include "ChessPiece.h"
#include "GameInfo.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include <iostream>

//square of the chessboard
//has a board position and can host a ChessPiece
class Square{
public:
	//can be initialized as an empty square
	Square(int row, int col);
	
	//can be intialized with a piece
	Square(int row, int col,PieceColor color, PieceType type);
	~Square();

	//returns true if there is a piece on the square
	bool Taken();
	
	//Getters and setters
	void SetPiece(ChessPiece * cp);
	void SetPiece(int row, int col, PieceColor color, PieceType type);
	ChessPiece * GetPiece();
	ChessPiece * MovePiece();
	int GetRow();
	int GetCol();
	//-----------------------
	
private:
	ChessPiece * piece;
	BoardPosition pos;
	//helper for constructor and set piece
	void CreatePiece(int row, int col, PieceColor color, PieceType type);
};

#endif