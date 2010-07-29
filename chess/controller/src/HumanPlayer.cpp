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

HumanPlayer::HumanPlayer(GameBoard * board,PieceColor color, MoveHistory * moves):
														ChessPlayer(board,color,moves){
	
}
bool HumanPlayer::on_CellSelected(int row, int col){
	bool changePlayer = false;
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
			Move m;
			m.SetMoveFrom(movingPiece);
			if (board->GetSquare(bp)->GetPiece() != NULL){
				m.SetKill(board->GetSquare(bp)->GetPiece());
				cout << "Kill color: " << m.GetColor(KILL) << "Kill type" << m.GetType(KILL) << endl;
				delete board->GetSquare(bp)->GetPiece();
			}
				
			movingPiece->SetBoardPosition(row,col);  //move the piece
			s->SetPiece(movingPiece);
			m.SetMoveTo(movingPiece);
			
			moves->Push(m);
			//need to push move to the move history here
			changePlayer = true;
		}  
		Init();
	} else 
		Init();
	return changePlayer;
	
}

bool HumanPlayer::on_TimerEvent(){
	return false;
}