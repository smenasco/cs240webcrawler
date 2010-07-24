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

Pawn::Pawn( PieceColor color): ChessPiece(color,PAWN){
	
}

Pawn::~Pawn(){
	
}

set<BoardPosition> Pawn::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	set<BoardPosition> validMoves;
	return validMoves;
}