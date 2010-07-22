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
#include "Square.h"
#include "GameBoard.h"
#include "GameInfo.h"



class Knight : public ChessPiece {
public:
	Knight(ChessColor color);
	
	~Knight();
	
	std::set<Square>  GetCandidateMoves(GameBoard * board, Square * s);
};
#endif