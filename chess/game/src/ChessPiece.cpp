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

using namespace std;
ChessPiece::ChessPiece(PieceColor color, PieceType type):color(color),type(type){
	
}

ChessPiece::~ChessPiece(){
	validMoves.erase(validMoves.begin(),validMoves.end());
}

void ChessPiece::SetBoardPosition(int row,int col){
	pos.SetRow(row);
	pos.SetCol(col);
}

const BoardPosition & ChessPiece::GetBoardPosition() const{
	return pos;
}

const PieceType ChessPiece::GetType() const{
	return type;
}

const PieceColor ChessPiece::GetColor() const { 
	return color;
}
