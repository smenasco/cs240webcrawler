/*
 *  Rook.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Rook.h"

using namespace std;

Rook::Rook( ChessColor color): ChessPiece(color,ROOK){
	
}

Rook::~Rook(){
	
}

set<Square> Rook::GetCandidateMoves(GameBoard * board, Square * s){
	set<Square> validMoves;
	return validMoves;
}