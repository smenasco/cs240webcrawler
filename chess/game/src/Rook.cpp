/*
 *  Rook.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Rook.h"
#include "Square.h"

using namespace std;

Rook::Rook( int row, int col, PieceColor color): ChessPiece(row,col,color,ROOK){
	
}

Rook::~Rook(){
	
}



void Rook::IterateSouth(GameBoard * board, BoardPosition pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetRow() +1;
	BoardPosition bp(pos.GetRow()+1,pos.GetCol());
	Square * s = board->GetSquare(bp);

	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetRow(++i);
		s = board->GetSquare(bp);
	}
}
void Rook::IterateNorth(GameBoard * board, BoardPosition pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetRow() -1;
	BoardPosition bp(pos.GetRow()-1,pos.GetCol());
	Square * s = board->GetSquare(bp);
	
	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetRow(--i);
		s = board->GetSquare(bp);
	}
}
void Rook::IterateEast(GameBoard * board, BoardPosition pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetCol() +1;
	BoardPosition bp(pos.GetRow(),pos.GetCol()+1);
	Square * s = board->GetSquare(bp);
	
	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetCol(++i);
		s = board->GetSquare(bp);
	}
}
void Rook::IterateWest(GameBoard * board, BoardPosition pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetCol() -1;
	BoardPosition bp(pos.GetRow(),pos.GetCol()-1);
	Square * s = board->GetSquare(bp);
	
	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetCol(--i);
		s = board->GetSquare(bp);
	}
}
bool Rook::CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp){
	if (s->Taken()){
		if (p->GetColor() != color){
			validMoves.insert(bp);
		}
		return false;
	} else{
		validMoves.insert(bp);
		return true;
	}
}

const set<BoardPosition> & Rook::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	validMoves.clear();
	IterateSouth(board,pos);
	IterateNorth(board,pos);
	IterateEast(board,pos);
	IterateWest(board,pos);
	

	
	return validMoves;
}