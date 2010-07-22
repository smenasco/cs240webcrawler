/*
 *  Bishop.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Bishop.h"

using namespace std;

Bishop::Bishop( ChessColor color): ChessPiece(color,BISHOP){
	 
}

Bishop::~Bishop(){
	
}

set<Square> Bishop::GetCandidateMoves(GameBoard * board, Square * s){
	set<Square> validMoves;
	return validMoves;
}