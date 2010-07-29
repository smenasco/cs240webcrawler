/*
 *  ChessPlayer.cpp
 *  project2
 *
 *  Created by Sam on 7/26/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "ChessPlayer.h"

using namespace std;

ChessPlayer::ChessPlayer(GameBoard * board, PieceColor color,MoveHistory * moves) : board(board), color(color),
	moves(moves){
	movingPiece = NULL;
	movingSquare = NULL;
}

void ChessPlayer::HighlightValidMoves(int row, int col){
	view->HighlightSquare(row, col,GREEN_SQUARE); //highlight selected square
	
	//now highlight all valid moves
	set<BoardPosition>::iterator it;
	
	for ( it=validMoves.begin() ; it != validMoves.end(); it++ )
		view->HighlightSquare((*it).GetRow(),(*it).GetCol(),BLUE_SQUARE);
	
	
	
}

void ChessPlayer::SetView(ChessView * view){
	this->view = view;
}

void ChessPlayer::Init(){
	
	for (int i = 0; i < 8;i++){
		for (int j=0;j < 8;j++){
			view->UnHighlightSquare(i,j);
		}
	}
	movingPiece = NULL;
	movingSquare = NULL;
	validMoves.clear();
}
bool ChessPlayer::IsCheckMate(){
	set<BoardPosition> pieceMoves;
	set<BoardPosition>::iterator it;

	ChessPiece * p;
	for (int i = 0; i < 8;i++){
		for (int j = 0; j < 8;j++){
			p = board->GetPiece(i,j);
			if (p != NULL && p->GetColor() == color){
				BoardPosition bp(i,j);
				pieceMoves = p->GetCandidateMoves(board,bp);
				pieceMoves = p->SimulateMoves(board,pieceMoves);
				
				for ( it=pieceMoves.begin() ; it != pieceMoves.end(); it++ ){
					return false;
				}
			}
		} 
	}
	return true;
}
bool ChessPlayer::IsInCheck(){
	king = board->FindMyKing(color);
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

