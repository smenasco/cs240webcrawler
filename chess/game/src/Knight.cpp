/*
 *  Knight.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Knight.h"

using namespace std;

Knight::Knight( PieceColor color): ChessPiece(color,KNIGHT){
	
}

Knight::~Knight(){
	
}

set<BoardPosition> Knight::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	set<BoardPosition> validMoves;
	return validMoves;
}