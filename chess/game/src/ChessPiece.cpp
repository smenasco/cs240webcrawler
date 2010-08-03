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
: pos(row,col),color(color),type(type){

}

ChessPiece::~ChessPiece(){
	//std::cout << "Delete piece: type:" << type << "color: " << color << std::endl;
	validMoves.clear();
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


set<BoardPosition> & ChessPiece::SimulateMoves(GameBoard * board,set<BoardPosition> & checkMoves){
	set<BoardPosition>::iterator it;
	ChessPiece * p;
	ChessPiece * temp;
	Square * s;
	p = board->GetSquare(pos)->MovePiece();

	for ( it=checkMoves.begin() ; it != checkMoves.end(); ){
		s = board->GetSquare(*it);
		temp = s->MovePiece();
		s->SetPiece(p);
		//move the piece
		if (IsInCheck(board)){
			checkMoves.erase(it++);

		}else 
			++it;
		s->SetPiece(temp);

	}
	/*for ( it=checkMoves.begin() ; it != checkMoves.end(); ){
		s = board->GetSquare(*it);
		temp = s->MovePiece();
		s->SetPiece(p);
		
		
		//move the piece
		if (IsInCheck(board)){
			checkMoves.erase(it++);
			
		}else 
			++it;
		s->SetPiece(temp);
	}*/
	board->GetSquare(pos)->SetPiece(p);

	return checkMoves;
}

bool ChessPiece::IsInCheck(GameBoard * board){
	BoardPosition king;
	king =board->FindMyKing(color);
	set<BoardPosition> pieceMoves;
	set<BoardPosition>::iterator it;
	
	
	ChessPiece * p;
	for (int i = 0; i < 8;i++){
		for (int j = 0; j < 8;j++){
			p = board->GetPiece(i,j);
			if (p != NULL && p->GetColor() != color){
				BoardPosition bp(i,j);
				pieceMoves = p->GetCandidateMoves(board,bp);
				for ( it=pieceMoves.begin() ; it != pieceMoves.end(); it++ ){
					//cout << (*it).GetRow() <<" "<< (*it).GetCol()<< endl;
					if (*it == king){
						return true;
					}
				}
			}
		} 
	}
	return false;
}
