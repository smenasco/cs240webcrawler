#ifndef KING_H
#define KING_H/*
 *  King.h
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


class King : public ChessPiece {
public:
	King(int row, int col, PieceColor color);
	
	~King();
	
	const std::set<BoardPosition> & GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	void CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};
#endif