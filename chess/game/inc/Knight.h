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



class Knight : public ChessPiece {
public:
	Knight(PieceColor color);
	
	~Knight();
	
	std::set<BoardPosition>  GetCandidateMoves(GameBoard * board, BoardPosition pos);
};
#endif