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
ChessPiece::ChessPiece(int row, int col, PieceColor color, PieceType type)
: pos(row,color),color(color),type(type),firstMove(true){
	origpos = pos;
}

ChessPiece::~ChessPiece(){
	validMoves.clear();
}
void ChessPiece::Move(){
	
}
bool ChessPiece::IsFirstMove(){
	if (!firstMove)
		return false;
	else {
		if (origpos != pos){
			firstMove = false;
			return false;
		} else
			return true;
	}
		
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
