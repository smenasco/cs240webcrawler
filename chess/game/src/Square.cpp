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
	std::cout << "Created a new empty square\n";
}

Square::Square(	int row, int col, PieceColor color, PieceType type ):pos(row,col){
	switch (type){
		case PAWN:
			piece = new Pawn(color);
			break;
		case ROOK:
			piece = new Rook(color);
			break;
		case KNIGHT:
			piece = new Knight(color);
			break;
		case BISHOP:
			piece = new Bishop(color);
			break;
		case KING:
			piece = new King(color);
			break;
		case QUEEN:
			piece = new Queen(color);
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