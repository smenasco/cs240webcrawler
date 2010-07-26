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
	for (int i = 0;i<32;i++){
		squares[i] = NULL;  //initialize squares[32] to NULL
	}
}

void GameBoard::Reset(){
	Clear();
	Init();
}

void GameBoard::Clear(){
	for (int i =0; i < 32;i++){
		if (squares[i] != NULL){
			delete squares[i]; //clean up memory of squares
		}
		
	}
	
	vector< vector<Square*> >::iterator it;
	for(it=board.begin(); it!=board.end(); it++)	{
		(*it).clear();  //clear columns
	}
	board.clear(); //clear rows
	
}

void GameBoard::Init(){
	Square *s;
	int count = 0;
	for ( int i = 0; i < 8; i++ ) {
		board.push_back ( vector<Square*>() );

		for ( int j = 0; j < 8; j++ ){
			switch (i){
				case 0:
					switch(j){
						case 0:
							s =  new Square(i,j,BLACK,ROOK);
							squares[count] = s;
							count++;
							board[i].push_back ( s );
							break;
						case 1:
							s=  new Square(i,j,BLACK,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 2:
							s=  new Square(i,j,BLACK,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 3:
							s = new Square(i,j,BLACK,KING);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 4:
							s = new Square(i,j,BLACK,QUEEN);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 5:
							s = new Square(i,j,BLACK,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 6:
							s = new Square(i,j,BLACK,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 7:
							s = new Square(i,j,BLACK,ROOK);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
					}
					break;
				case 1:
					s = new Square(i,j,BLACK,PAWN);
					squares[count] = s;
					board[i].push_back ( s );
					count++;
					break;
				case 6:
					s = new Square(i,j,WHITE,PAWN);
					squares[count] = s;
					board[i].push_back ( s );
					count++;
					break;
				case 7:
					switch(j){
						case 0:
							s = new Square(i,j,WHITE,ROOK);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 1:
							s = new Square(i,j,WHITE,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 2:
							s = new Square(i,j,WHITE,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 3:
							s = new Square(i,j,WHITE,KING);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 4:
							s = new Square(i,j,WHITE,QUEEN);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 5:
							s = new Square(i,j,WHITE,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 6:
							s = new Square(i,j,WHITE,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 7:
							s = new Square(i,j,WHITE,ROOK);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
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
	if (pos.GetRow() >=0 && pos.GetRow() <8 &&
		pos.GetCol() >=0 && pos.GetCol() <8  ){
		return board[pos.GetRow()][pos.GetCol()];
	} else
		return NULL;
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