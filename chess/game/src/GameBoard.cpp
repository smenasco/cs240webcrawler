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
	for ( int i = 0; i < 8; i++ ) {
		board.push_back ( vector<Square*>() );
		
		for ( int j = 0; j < 8; j++ ){
			switch (i){
				case 0:
					switch(j){
						case 0:
							board[i].push_back ( new Square(BLACK,ROOK) );
							break;
						case 1:
							board[i].push_back ( new Square(BLACK,KNIGHT) );
							break;
						case 2:
							board[i].push_back ( new Square(BLACK,BISHOP) );
							break;
						case 3:
							board[i].push_back ( new Square(BLACK,KING) );
							break;
						case 4:
							board[i].push_back ( new Square(BLACK,QUEEN) );
							break;
						case 5:
							board[i].push_back ( new Square(BLACK,BISHOP) );
							break;
						case 6:
							board[i].push_back ( new Square(BLACK,KNIGHT) );
							break;
						case 7:
							board[i].push_back ( new Square(BLACK,ROOK) );
							break;
					}
					break;
				case 1:
					board[i].push_back ( new Square(BLACK,PAWN) );
					break;
				case 6:
					board[i].push_back ( new Square(WHITE,PAWN) );
					break;
				case 7:
					switch(j){
						case 0:
							board[i].push_back ( new Square(WHITE,ROOK) );
							break;
						case 1:
							board[i].push_back ( new Square(WHITE,KNIGHT) );
							break;
						case 2:
							board[i].push_back ( new Square(WHITE,BISHOP) );
							break;
						case 3:
							board[i].push_back ( new Square(WHITE,KING) );
							break;
						case 4:
							board[i].push_back ( new Square(WHITE,QUEEN) );
							break;
						case 5:
							board[i].push_back ( new Square(WHITE,BISHOP) );
							break;
						case 6:
							board[i].push_back ( new Square(WHITE,KNIGHT) );
							break;
						case 7:
							board[i].push_back ( new Square(WHITE,ROOK) );
							break;
					}
					break;
				default:
					board[i].push_back ( new Square() );
			}
		}
		
	}
	
}

Square * GameBoard::GetSquare(int row, int col){
	return board[row][col];
}
