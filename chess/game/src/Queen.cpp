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

Queen::Queen( ChessColor color): ChessPiece(color,QUEEN){
	
}

Queen::~Queen(){
	
}

set<Square> Queen::GetCandidateMoves(GameBoard * board, Square * s){
	set<Square> validMoves;
	return validMoves;
}