/*
 *  GameBoard.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "GameBoard.h"
#include "GameInfo.h"

using namespace std;

GameBoard::GameBoard(){
	
}

void GameBoard::Reset(){
	Clear();
	Init();
}

void GameBoard::Clear(){
	
	
	vector< vector<Square*> >::iterator it;
	vector<Square*>::iterator sit;
	for(it=board.begin(); it!=board.end(); it++)	{
		for(sit=(*it).begin(); sit!=(*it).end(); sit++)	{
			delete *sit;
		}
		(*it).clear();  //clear columns
	}
	board.clear(); //clear rows
	
}

void GameBoard::Init(){
	Square *s;
	for ( int i = 0; i < 8; i++ ) {
		board.push_back ( vector<Square*>() );

		for ( int j = 0; j < 8; j++ ){
			switch (i){
				case 0:
					switch(j){
						case 0:
							s =  new Square(i,j,BLACK,ROOK);
							board[i].push_back ( s );
							break;
						case 1:
							s=  new Square(i,j,BLACK,KNIGHT);
							board[i].push_back ( s );
							break;
						case 2:
							s=  new Square(i,j,BLACK,BISHOP);
							board[i].push_back ( s );
							break;
						case 3:
							s = new Square(i,j,BLACK,KING);
							board[i].push_back ( s );
							break;
						case 4:
							s = new Square(i,j,BLACK,QUEEN);
							board[i].push_back ( s );
							break;
						case 5:
							s = new Square(i,j,BLACK,BISHOP);
							board[i].push_back ( s );
							break;
						case 6:
							s = new Square(i,j,BLACK,KNIGHT);
							board[i].push_back ( s );
							break;
						case 7:
							s = new Square(i,j,BLACK,ROOK);
							board[i].push_back ( s );
							break;
					}
					break;
				case 1:
					s = new Square(i,j,BLACK,PAWN);
					board[i].push_back ( s );
					break;
				case 6:
					s = new Square(i,j,WHITE,PAWN);
					board[i].push_back ( s );
					break;
				case 7:
					switch(j){
						case 0:
							s = new Square(i,j,WHITE,ROOK);
							board[i].push_back ( s );
							break;
						case 1:
							s = new Square(i,j,WHITE,KNIGHT);
							board[i].push_back ( s );
							break;
						case 2:
							s = new Square(i,j,WHITE,BISHOP);
							board[i].push_back ( s );
							break;
						case 3:
							s = new Square(i,j,WHITE,KING);
							board[i].push_back ( s );
							break;
						case 4:
							s = new Square(i,j,WHITE,QUEEN);
							board[i].push_back ( s );
							break;
						case 5:
							s = new Square(i,j,WHITE,BISHOP);
							board[i].push_back ( s );
							break;
						case 6:
							s = new Square(i,j,WHITE,KNIGHT);
							board[i].push_back ( s );
							break;
						case 7:
							s = new Square(i,j,WHITE,ROOK);
							board[i].push_back ( s );
							break;
					}
					break;
				default:
					board[i].push_back ( new Square(i,j) );
					break;
			}
		}
		
	}
}

Square * GameBoard::GetSquare(int row, int col){
	if (row >=0 && row <8 && col >=0 && col <8  )
		return board[row][col];
	else
		return NULL;
}

Square * GameBoard::GetSquare(BoardPosition pos){
	return GetSquare(pos.GetRow(), pos.GetCol());
}
ChessPiece * GameBoard::GetPiece(int row, int col){
	Square * s;
	s = GetSquare(row,col);
	if (s != NULL)
		return s->GetPiece();
	else 
		return NULL;

}
ChessPiece * GameBoard::GetPiece(BoardPosition pos){
	return GetPiece(pos.GetRow(), pos.GetCol());
}
const BoardPosition GameBoard::FindMyKing(PieceColor color){
	Square * s;
	BoardPosition bp;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			s = GetSquare(i,j);
			ChessPiece *p=s->GetPiece();
			if (p != NULL){
				if (p->GetType()==KING && p->GetColor() == color){
					bp.SetRow(i);
					bp.SetCol(j);
				}
					 
			}
		}
	}
	return bp;
}