/*
 *  Bishop.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Bishop.h"
#include "Square.h"
using namespace std;

Bishop::Bishop( int row, int col, PieceColor color): ChessPiece(row,col,color,BISHOP){
	 
}

Bishop::~Bishop(){
	
}

void Bishop::IterateSouthWest(GameBoard * board,BoardPosition  pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetRow() +1;
	int j = pos.GetCol()-1;
	BoardPosition bp(pos.GetRow()+1,pos.GetCol()-1);
	Square * s = board->GetSquare(bp);
	
	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetRow(++i);
		bp.SetCol(--j);
		s = board->GetSquare(bp);
	}
}
void Bishop::IterateSouthEast(GameBoard * board,BoardPosition  pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetRow() +1;
	int j = pos.GetCol()+1;
	BoardPosition bp(pos.GetRow()+1,pos.GetCol()+1);
	Square * s = board->GetSquare(bp);
	
	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetRow(++i);
		bp.SetCol(++j);
		s = board->GetSquare(bp);
	}
}
void Bishop::IterateNorthWest(GameBoard * board,BoardPosition  pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetRow() -1;
	int j = pos.GetCol()-1;
	BoardPosition bp(pos.GetRow()-1,pos.GetCol()-1);
	Square * s = board->GetSquare(bp);
	
	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetRow(--i);
		bp.SetCol(--j);
		s = board->GetSquare(bp);
	}
}
void Bishop::IterateNorthEast(GameBoard * board,BoardPosition  pos){
	bool canAdd = true;
	ChessPiece *p;
	int i = pos.GetRow() -1;
	int j = pos.GetCol()+1;
	BoardPosition bp(pos.GetRow()-1,pos.GetCol()+1);
	Square * s = board->GetSquare(bp);
	
	while(s != NULL  && canAdd){
		p = s->GetPiece();
		
		canAdd = CheckForPieces(p,s,bp);
		
		bp.SetRow(--i);
		bp.SetCol(++j);
		s = board->GetSquare(bp);
	}
}
bool Bishop::CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp){
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
const set<BoardPosition> & Bishop::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	validMoves.clear();
	IterateSouthWest(board,pos);
	IterateSouthEast(board,pos);
	IterateNorthWest(board,pos);
	IterateNorthEast(board,pos);
	
	return validMoves;
}