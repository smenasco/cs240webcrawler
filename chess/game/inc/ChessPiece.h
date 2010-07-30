#ifndef CHESSPIECE_H
#define CHESSPIECE_H

/*
 *  ChessPiece.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include <set>
#include "GameInfo.h"
#include "BoardPosition.h"
class GameBoard;
class Square;

//mother of all chess pieces. super class
class ChessPiece {
public:
	ChessPiece(int row, int col,PieceColor color, PieceType type);
	~ChessPiece();
	
	//Getters and setters
	const PieceColor GetColor() const;
	const PieceType GetType() const;
	void SetBoardPosition(int row,int col);
	const BoardPosition & GetBoardPosition() const;
	
	//returns a set of moves for a particular chess piece.
	//implemented in respective chesspiece sub classes
	virtual const std::set<BoardPosition> & GetCandidateMoves(GameBoard * board, BoardPosition pos) = 0;
	
	//simulates the valid moves using a set of valid moves: checkMoves
	//this is to validate whether or not the piece will move the king into check
	//in the case that it does the move is removed from the set and the
	//final set is returned
	std::set<BoardPosition> & SimulateMoves(GameBoard * board,std::set<BoardPosition> & checkMoves);
protected:
	std::set<BoardPosition> validMoves;
	BoardPosition pos;
	PieceColor color;
	PieceType type;
	
	//Used by simulate moves to create valid moves
	bool IsInCheck(GameBoard * board);
	
};


#endif