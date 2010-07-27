/*
 *  Queen.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Queen.h"
#include "Square.h"

using namespace std;

Queen::Queen( int row, int col, PieceColor color): ChessPiece(row,col,color,QUEEN){
	
}

Queen::~Queen(){
	
}

void Queen::IterateSouth(GameBoard * board, BoardPosition pos){
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
void Queen::IterateNorth(GameBoard * board, BoardPosition pos){
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
void Queen::IterateEast(GameBoard * board, BoardPosition pos){
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
void Queen::IterateWest(GameBoard * board, BoardPosition pos){
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
void Queen::IterateSouthWest(GameBoard * board,BoardPosition  pos){
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
void Queen::IterateSouthEast(GameBoard * board,BoardPosition  pos){
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
void Queen::IterateNorthWest(GameBoard * board,BoardPosition  pos){
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
void Queen::IterateNorthEast(GameBoard * board,BoardPosition  pos){
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
bool Queen::CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp){
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

const set<BoardPosition> & Queen::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	validMoves.clear();
	
	IterateSouth(board,pos);
	IterateNorth(board,pos);
	IterateEast(board,pos);
	IterateWest(board,pos);
	IterateSouthWest(board,pos);
	IterateSouthEast(board,pos);
	IterateNorthWest(board,pos);
	IterateNorthEast(board,pos);
	
	
	
	return validMoves;
}