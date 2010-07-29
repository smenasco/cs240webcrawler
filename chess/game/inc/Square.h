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

class Square{
public:
	Square(int row, int col);
	Square(int row, int col,PieceColor color, PieceType type);
	~Square();
	bool Taken();
	void SetPiece(ChessPiece * cp);
	void SetPiece(int row, int col, PieceColor color, PieceType);
	
	ChessPiece * GetPiece();
	ChessPiece * MovePiece();
	int GetRow();
	int GetCol();
private:
	ChessPiece * piece;
	BoardPosition pos;
	
	void CreatePiece(int row, int col, PieceColor color, PieceType type);
};

#endif