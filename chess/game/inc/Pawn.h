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
#include "Square.h"
#include "GameBoard.h"
#include "GameInfo.h"



class Pawn : public ChessPiece {
public:
	Pawn(ChessColor color);
	
	~Pawn();
	
	std::set<Square>  GetCandidateMoves(GameBoard * board, Square * s);
};
#endif