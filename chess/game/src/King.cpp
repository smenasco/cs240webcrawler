/*
 *  King.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "King.h"

using namespace std;

King::King( ChessColor color): ChessPiece(color,KING){
	
}

King::~King(){
	
}

set<Square> King::GetCandidateMoves(GameBoard * board, Square * s){
	set<Square> validMoves;
	return validMoves;
}