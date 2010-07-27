/*
 *  CompPlayer.cpp
 *  project2
 *
 *  Created by Sam on 7/26/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "CompPlayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

CompPlayer::CompPlayer(GameBoard * board,PieceColor color): ChessPlayer(board,color){
	row = -1;
	col = -1;
}

bool CompPlayer::on_CellSelected(int row, int col){
	return false;
}

bool CompPlayer::on_TimerEvent(){
	bool changePlayer = false;
	PieceColor movingPieceColor;
	int random, size=0;
	srand(time(NULL));
	int count = 0;
	ChessPiece * pieces[16];
	
	for (int i = 0; i < 16;i++){
		pieces[i] =NULL;
	}
	/* generate random number: */

	BoardPosition bp;
	
	if (row == -1 && col == -1) {
		validMoves.clear();
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				movingPiece = board->GetPiece(i,j);
				
				if (movingPiece != NULL){
					movingPieceColor = movingPiece->GetColor();
					validMoves = movingPiece->GetCandidateMoves(board,BoardPosition(i,j)); //getvaild moves
					validMoves = movingPiece->SimulateMoves(board,validMoves);
					size = validMoves.size();
					if (movingPieceColor == color && size >0){
						pieces[count] = movingPiece;
						count ++;
					}
				}
			}
		}
		if (count == 1 )
			count = 2;
		random= rand() % (count -1);
		//cout << random << " " << count<< endl;
		movingPiece = pieces[random];
		
		bp = movingPiece->GetBoardPosition();	
		movingPiece = board->GetSquare(bp)->GetPiece();
		row = bp.GetRow();
		col = bp.GetCol();
		validMoves = movingPiece->GetCandidateMoves(board,BoardPosition(row,col)); //getvaild moves
		validMoves = movingPiece->SimulateMoves(board,validMoves);
		size = validMoves.size();
		//cout << "Row: " << row << " col: " << col << endl; 
		
		HighlightValidMoves(row,col);  //highlight valid moves
		movingPiece = board->GetSquare(bp)->MovePiece();
	} else {
		
		bp = *validMoves.begin();
		Square * s = board->GetSquare(bp);
		
		if (s->GetPiece() != NULL)
			delete board->GetSquare(bp)->GetPiece();
		if (movingPiece != NULL) {
			movingPiece->SetBoardPosition(bp.GetRow(),bp.GetCol());  //move the piece
			s->SetPiece(movingPiece);
			changePlayer = true;
		}
			
		row = -1;
		col = -1;
		Init();
			
			//need to push move to the move history here
	}
	return changePlayer;
}