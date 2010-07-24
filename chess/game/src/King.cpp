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

King::King( PieceColor color): ChessPiece(color,KING){
	
}

King::~King(){
	
}

const set<BoardPosition> & King::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	return validMoves;
}