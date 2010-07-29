/*
 *  Square.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Square.h"

Square::Square(int row, int col) : piece(NULL),pos(row,col) {
	//creates an empty square
}

Square::Square(	int row, int col, PieceColor color, PieceType type ):pos(row,col){
	CreatePiece(row,col,color,type);
}

void Square::CreatePiece(int row, int col, PieceColor color, PieceType type){
	switch (type){
		case PAWN:
			piece = new Pawn(row,col,color);
			break;
		case ROOK:
			piece = new Rook(row,col,color);
			break;
		case KNIGHT:
			piece = new Knight(row,col,color);
			break;
		case BISHOP:
			piece = new Bishop(row,col,color);
			break;
		case KING:
			piece = new King(row,col,color);
			break;
		case QUEEN:
			piece = new Queen(row,col,color);
			break;
	}
}



Square::~Square(){
	if (piece != NULL)
		delete piece;
}



bool Square::Taken(){
	if (piece == NULL)
		return false;
	else 
		return true;
}
void Square::SetPiece(int row, int col, PieceColor color, PieceType type){
	CreatePiece(row,col,color,type);	
}
void Square::SetPiece(ChessPiece * cp){
		piece = cp;
}

ChessPiece * Square::GetPiece(){
	if (piece == NULL)
		return NULL;
	else
		return piece;
}
int Square::GetRow(){
	return pos.GetRow();
}
int Square::GetCol(){
	return pos.GetCol();
}

ChessPiece * Square::MovePiece(){
	ChessPiece * thepiece = piece;
	piece = NULL;
	return thepiece;
}