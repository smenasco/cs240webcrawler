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


class Knight : public ChessPiece {
public:
	Knight(int row, int col, PieceColor color);
	
	~Knight();
	
	const std::set<BoardPosition> &  GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	void CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};
#endif