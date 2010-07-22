/*
 *  Pawn.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Pawn.h"

using namespace std;

Pawn::Pawn( ChessColor color): ChessPiece(color,PAWN){
	
}

Pawn::~Pawn(){
	
}

set<Square> Pawn::GetCandidateMoves(GameBoard * board, Square * s){
	set<Square> validMoves;
	return validMoves;
}