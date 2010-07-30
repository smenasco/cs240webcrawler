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

//chess piece subclass implements king
class King : public ChessPiece {
public:
	
	//creates a new king and sets its board position and color
	King(int row, int col, PieceColor color);
	
	~King();
	
	//implemnts checkcandidate moves from superclass
	const std::set<BoardPosition> & GetCandidateMoves(GameBoard * board, BoardPosition pos);
private:
	
	//helper class for get candidate moves
	void CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp);
};
#endif