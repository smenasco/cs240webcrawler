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



class Queen : public ChessPiece {
public:
	Queen(PieceColor color);
	
	~Queen();
	
	std::set<BoardPosition>  GetCandidateMoves(GameBoard * board, BoardPosition pos);
};
#endif