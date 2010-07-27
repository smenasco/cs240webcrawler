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
: pos(row,col),color(color),type(type),firstMove(true){
	origpos = pos;
}

ChessPiece::~ChessPiece(){
	//std::cout << "Delete piece: type:" << type << "color: " << color << std::endl;
	validMoves.clear();
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


set<BoardPosition> & ChessPiece::SimulateMoves(GameBoard * board,set<BoardPosition> & checkMoves){
	set<BoardPosition>::iterator it;
	ChessPiece * p;
	ChessPiece * temp;
	p = board->GetSquare(pos)->MovePiece();
 	cout << "Currently checking square: [" << pos.GetRow() << "," << pos.GetCol() << "]\n";
	for ( it=checkMoves.begin() ; it != checkMoves.end(); it++ ){
		
		temp = board->GetPiece(*it);
		board->GetSquare(*it)->SetPiece(p);//move the piece
		if (IsInCheck(board)){
			checkMoves.erase(it);
			cout << "found invalid move\n";
		}
		board->GetSquare(*it)->SetPiece(temp);
	}
	board->GetSquare(pos)->SetPiece(p);
	return checkMoves;
}

bool ChessPiece::IsInCheck(GameBoard * board){
	BoardPosition king = board->FindMyKing(color);
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
					if (*it == king){
						return true;
					}
				}
			}
		} 
	}
	return false;
}