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

Bishop::Bishop( PieceColor color): ChessPiece(color,BISHOP){
	 
}

Bishop::~Bishop(){
	
}

const set<BoardPosition> & Bishop::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	
	return validMoves;
}