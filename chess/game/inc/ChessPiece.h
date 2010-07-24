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
	ChessPiece(PieceColor color, PieceType type);
	const PieceColor GetColor() const;
	const PieceType GetType() const;
	
	virtual std::set<BoardPosition>  GetCandidateMoves(GameBoard * board, BoardPosition pos) = 0;
	
protected:
	PieceColor color;
	PieceType type;
};


#endif