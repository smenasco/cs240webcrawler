/*
 *  ChessPiece.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */


#include "GameBoard.h"
#include "BoardPosition.h"
#include "ChessPiece.h"


ChessPiece::ChessPiece(PieceColor color, PieceType type):color(color),type(type){
	
}

const PieceType ChessPiece::GetType() const{
	return type;
}

const PieceColor ChessPiece::GetColor() const { 
	return color;
}
