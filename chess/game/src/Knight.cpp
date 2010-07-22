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

Knight::Knight( ChessColor color): ChessPiece(color,KNIGHT){
	
}

Knight::~Knight(){
	
}

set<Square> Knight::GetCandidateMoves(GameBoard * board, Square * s){
	set<Square> validMoves;
	return validMoves;
}