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

Rook::Rook( PieceColor color): ChessPiece(color,ROOK){
	
}

Rook::~Rook(){
	
}

const set<BoardPosition> & Rook::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	
	return validMoves;
}