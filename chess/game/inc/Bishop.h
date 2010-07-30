#ifndef BISHOP_H
#define BISHOP_H
/*
 *  Bishop.h
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


class Bishop : public ChessPiece {
public:
	Bishop(int row, int col, PieceColor color);
	
	~Bishop();
	//finds valid moves for currently selected bishop
	const std::set<BoardPosition> & GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	//the following methods are used by GetCandidateMoves to find valid moves
	void IterateSouthWest(GameBoard * board,BoardPosition  pos);
	void IterateSouthEast(GameBoard * board,BoardPosition  pos);
	void IterateNorthWest(GameBoard * board,BoardPosition  pos);
	void IterateNorthEast(GameBoard * board,BoardPosition  pos);
	bool CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};

#endif