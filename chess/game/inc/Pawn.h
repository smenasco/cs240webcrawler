#ifndef PAWN_H
#define PAWN_H/*
 *  Pawn.h
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

//chess piece subclass implements pawn
class Pawn : public ChessPiece {
public:
	//creates a new pawn and sets its board position and color
	Pawn(int row, int col, PieceColor color);
	~Pawn();
	
	//implemnts checkcandidate moves from superclass
	const std::set<BoardPosition> &  GetCandidateMoves(GameBoard * board, BoardPosition pos);

};
#endif