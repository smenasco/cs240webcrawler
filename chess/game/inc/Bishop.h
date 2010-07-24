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



class Bishop : public ChessPiece {
public:
	Bishop(PieceColor color);
	
	~Bishop();
	
	std::set<BoardPosition> GetCandidateMoves(GameBoard * board, BoardPosition pos);
};

#endif