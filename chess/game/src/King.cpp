/*
 *  King.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "King.h"
#include "Square.h"

using namespace std;

King::King( int row, int col, PieceColor color): ChessPiece(row,col,color,KING){
	
}

King::~King(){
	
}

void King::CheckForPieces(ChessPiece * p, Square * s, BoardPosition bp){
	if (s->Taken()){
		if (p->GetColor() != color){
			validMoves.insert(bp);
		}
	} else{
		validMoves.insert(bp);
	}
}

const set<BoardPosition> & King::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	validMoves.clear();

	BoardPosition bp;
	Square * s;
	ChessPiece * p;
	for (int i = 0; i < 8; i++) {
		switch (i){
			case 0:
				bp.SetRow(pos.GetRow()-1);
				bp.SetCol(pos.GetCol()+0);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
			case 1:
				bp.SetRow(pos.GetRow()-1);
				bp.SetCol(pos.GetCol()+1);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
			case 2:
				bp.SetRow(pos.GetRow()+0);
				bp.SetCol(pos.GetCol()+1);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
			case 3:
				bp.SetRow(pos.GetRow()+1);
				bp.SetCol(pos.GetCol()+1);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
			case 4:
				bp.SetRow(pos.GetRow()+1);
				bp.SetCol(pos.GetCol()+0);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
			case 5:
				bp.SetRow(pos.GetRow()+1);
				bp.SetCol(pos.GetCol()-1);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
			case 6:
				bp.SetRow(pos.GetRow()+0);
				bp.SetCol(pos.GetCol()-1);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
			case 7:
				bp.SetRow(pos.GetRow()-1);
				bp.SetCol(pos.GetCol()-1);
				s = board->GetSquare(bp);
				if (s!=NULL){
					p = s->GetPiece();
					CheckForPieces(p,s,bp);
				}
				break;
		}
	}
	
	
	
	return validMoves;
}

