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


class Queen : public ChessPiece {
public:
	Queen(int row, int col, PieceColor color);
	
	~Queen();
	
	const std::set<BoardPosition> &  GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
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