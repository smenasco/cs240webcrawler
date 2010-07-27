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

class ChessPiece {
public:
	ChessPiece(int row, int col,PieceColor color, PieceType type);
	~ChessPiece();
	const PieceColor GetColor() const;
	const PieceType GetType() const;
	void SetBoardPosition(int row,int col);
	const BoardPosition & GetBoardPosition() const;
	virtual const std::set<BoardPosition> & GetCandidateMoves(GameBoard * board, BoardPosition pos) = 0;
	bool IsFirstMove();

	std::set<BoardPosition> & SimulateMoves(GameBoard * board,std::set<BoardPosition> & checkMoves);
protected:
	std::set<BoardPosition> validMoves;
	BoardPosition pos;
	PieceColor color;
	PieceType type;
	bool firstMove;
	BoardPosition origpos;
	bool IsInCheck(GameBoard * board);
};


#endif