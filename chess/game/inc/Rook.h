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


class Rook : public ChessPiece {
public:
	Rook(int row, int col, PieceColor color);
	
	~Rook();
	
	const std::set<BoardPosition> &  GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	void IterateSouth(GameBoard * board, BoardPosition pos);
	void IterateNorth(GameBoard * board, BoardPosition pos);
	void IterateEast(GameBoard * board, BoardPosition pos);
	void IterateWest(GameBoard * board, BoardPosition pos);
	bool CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};
#endif