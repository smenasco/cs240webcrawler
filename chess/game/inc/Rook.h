#ifndef ROOK_H
#define ROOK_H
/*
 *  Rook.h
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

//chess piece subclass implements rook
class Rook : public ChessPiece {
public:
	//creates a new rook and sets its board position and color
	Rook(int row, int col, PieceColor color);
	
	~Rook();
	
	//implemnts checkcandidate moves from superclass
	const std::set<BoardPosition> &  GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	//helper functions for GetCandidateMoves
	void IterateSouth(GameBoard * board, BoardPosition pos);
	void IterateNorth(GameBoard * board, BoardPosition pos);
	void IterateEast(GameBoard * board, BoardPosition pos);
	void IterateWest(GameBoard * board, BoardPosition pos);
	bool CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};
#endif