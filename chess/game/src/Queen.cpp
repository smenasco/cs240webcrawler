/*
 *  Queen.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Queen.h"

using namespace std;

Queen::Queen( PieceColor color): ChessPiece(color,QUEEN){
	
}

Queen::~Queen(){
	
}

set<BoardPosition> Queen::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	set<BoardPosition> validMoves;
	return validMoves;
}