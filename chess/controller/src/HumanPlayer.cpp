/*
 *  HumanPlayer.cpp
 *  project2
 *
 *  Created by Sam on 7/26/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(GameBoard * board,PieceColor color): ChessPlayer(board,color){
	
}
bool HumanPlayer::on_CellSelected(int row, int col){
	bool changePlayer = false;
	//IsInCheck();
	if (movingSquare == NULL && movingPiece == NULL) {
		validMoves.clear();
		movingSquare = board->GetSquare(row,col);
		movingPiece = board->GetSquare(row,col)->GetPiece();
		if (movingPiece != NULL){
			//check to see if piece is your team
			if (movingPiece->GetColor() == color){
				view->HighlightSquare(row, col,GREEN_SQUARE);  //highlight currently selected piece
				
				validMoves = movingPiece->GetCandidateMoves(board,BoardPosition(row,col)); //getvaild moves
				validMoves = movingPiece->SimulateMoves(board,validMoves);
				HighlightValidMoves(row,col);  //highlight valid moves
			}else
				Init();
			
		}
		
	} else if (movingSquare != NULL && movingPiece != NULL){
		Square * s = board->GetSquare(row,col);
		
		
		set<BoardPosition>::iterator it;
		BoardPosition bp(row,col);			//check to see if the suggested
		it=validMoves.find(bp);				//move is valid
		if (it != validMoves.end()){  //currently selected move is valid
			movingPiece = movingSquare->MovePiece();
			
			if (board->GetSquare(bp)->GetPiece() != NULL)
				delete board->GetSquare(bp)->GetPiece();
			movingPiece->SetBoardPosition(row,col);  //move the piece
			s->SetPiece(movingPiece);
			changePlayer = true;
			//need to check for check/checkmate/stalemate
			//need to push move to the move history here
		}  
		Init();
	} else 
		Init();
	return changePlayer;
	
}

bool HumanPlayer::on_TimerEvent(){
	return false;
}