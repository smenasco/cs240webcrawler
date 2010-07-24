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
		squares[i] = NULL;
	}
	firstTime = true;
	Init();
}

void GameBoard::Reset(){
	Clear();
	Init();
}

void GameBoard::Clear(){
	for (int i =0; i < 32;i++){
		if (squares[i] != NULL){
			delete squares[i];
		}
		
	}
	if (!firstTime){
		for (int i = 0; i < 8;i++)  {
			for (int j = 0; j < 8; j++ ){
				board[i][j] = NULL;
			}
		}
	}
	firstTime = false;
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
							s =  new Square(BLACK,ROOK);
							squares[count] = s;
							count++;
							board[i].push_back ( s );
							break;
						case 1:
							s=  new Square(BLACK,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 2:
							s=  new Square(BLACK,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 3:
							s = new Square(BLACK,KING);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 4:
							s = new Square(BLACK,QUEEN);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 5:
							s = new Square(BLACK,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 6:
							s = new Square(BLACK,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 7:
							s = new Square(BLACK,ROOK);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
					}
					break;
				case 1:
					s = new Square(BLACK,PAWN);
					squares[count] = s;
					board[i].push_back ( s );
					count++;
					break;
				case 6:
					s = new Square(WHITE,PAWN);
					squares[count] = s;
					board[i].push_back ( s );
					count++;
					break;
				case 7:
					switch(j){
						case 0:
							s = new Square(WHITE,ROOK);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 1:
							s = new Square(WHITE,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 2:
							s = new Square(WHITE,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 3:
							s = new Square(WHITE,KING);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 4:
							s = new Square(WHITE,QUEEN);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 5:
							s = new Square(WHITE,BISHOP);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 6:
							s = new Square(WHITE,KNIGHT);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
						case 7:
							s = new Square(WHITE,ROOK);
							squares[count] = s;
							board[i].push_back ( s );
							count++;
							break;
					}
					break;
				default:
					board[i].push_back ( new Square() );
					break;
			}
		}
		
	}
}

Square * GameBoard::GetSquare(int row, int col){
	return board[row][col];
}
