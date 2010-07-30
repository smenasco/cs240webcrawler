#ifndef KNIGHT_H
#define KNIGHT_H
/*
 *  Knight.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include <set>
#include "BoardPosition.h"
#include "GameBoard.h"
#include "GameInfo.h"
class Square;

//chess piece subclass implements knight
class Knight : public ChessPiece {
	
	//creates a new knight and sets its board position and color
	Knight(int row, int col, PieceColor color);
	
	~Knight();
	//implemnts checkcandidate moves from superclass
	const std::set<BoardPosition> &  GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	//helper class for get candidate moves	
	void CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};
#endif