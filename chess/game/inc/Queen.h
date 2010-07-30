#ifndef QUEEN_H
#define QUEEN_H
/*
 *  Queen.h
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

//chess piece subclass implements queen
class Queen : public ChessPiece {
public:
	//creates a new queen and sets its board position and color
	Queen(int row, int col, PieceColor color);
	
	~Queen();
		//implemnts checkcandidate moves from superclass
	const std::set<BoardPosition> &  GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	//helper functions for GetCandidateMoves
	void IterateSouth(GameBoard * board, BoardPosition pos);
	void IterateNorth(GameBoard * board, BoardPosition pos);
	void IterateEast(GameBoard * board, BoardPosition pos);
	void IterateWest(GameBoard * board, BoardPosition pos);
	void IterateSouthWest(GameBoard * board,BoardPosition  pos);
	void IterateSouthEast(GameBoard * board,BoardPosition  pos);
	void IterateNorthWest(GameBoard * board,BoardPosition  pos);
	void IterateNorthEast(GameBoard * board,BoardPosition  pos);
	bool CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};
#endif