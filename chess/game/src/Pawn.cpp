/*
 *  Pawn.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Pawn.h"
#include "Square.h"
using namespace std;

Pawn::Pawn( int row, int col, PieceColor color): ChessPiece(row,col,color,PAWN){
	
}



Pawn::~Pawn(){
	
}

const set<BoardPosition> & Pawn::GetCandidateMoves(GameBoard * board, BoardPosition pos){
	validMoves.clear();
	
	Moves mv1;
	Moves mv2;
	Moves at1;
	Moves at2;
	BoardPosition bpmv1(pos.GetRow()+(1*color),pos.GetCol());
	BoardPosition bpmv2(pos.GetRow()+(2*color),pos.GetCol());
	BoardPosition bpat1(pos.GetRow()+(1*color),pos.GetCol()+1);
	BoardPosition bpat2(pos.GetRow()+(1*color),pos.GetCol()-1);
	
	Square * s = board->GetSquare(bpmv1);
	if (s !=NULL)
		mv1 = (Moves)s->Taken();
	else
		mv1 = dne;
	s=board->GetSquare(bpmv2);
	if (s !=NULL)
		mv2 = (Moves)s->Taken();
	else
		mv2 = dne;
	s=board->GetSquare(bpat1);
	if (s !=NULL)
		at1 = (Moves)s->Taken();
	else
		at1 = dne;
	s=board->GetSquare(bpat2);
	if (s !=NULL)
		at2 = (Moves)s->Taken();
	else
		at2 = dne;
	
	
	if ((pos.GetRow() == 1 && color == BLACK) || 
		(pos.GetRow() == 6 && color == WHITE)){
		if (mv1 == empty)
			validMoves.insert(bpmv1);
		if (mv1 == empty && mv2 == empty)
			validMoves.insert(bpmv2);
	} else{
		if (mv1 == empty) 
			validMoves.insert(bpmv1);
	}
	ChessPiece * p;
	if (at1 == taken){
		s = board->GetSquare(bpat1);
		p = s->GetPiece();
		if (p->GetColor() != color)
			validMoves.insert(bpat1);
	}
	if (at2 == taken){
		s = board->GetSquare(bpat2);
		p = s->GetPiece();
		if (p->GetColor() != color)
			validMoves.insert(bpat2);
	}	
	
	return validMoves;
}