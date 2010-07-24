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



class Rook : public ChessPiece {
public:
	Rook(PieceColor color);
	
	~Rook();
	
	std::set<BoardPosition>  GetCandidateMoves(GameBoard * board, BoardPosition pos);
};
#endif