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

#include "Square.h"
#include "GameInfo.h"
class GameBoard;

class ChessPiece {
public:
	ChessPiece(ChessColor color, PieceType type);
	const ChessColor GetColor() const;
	const PieceType GetType() const;
	
	virtual std::set<Square>  GetCandidateMoves(GameBoard * board, Square * s) = 0;
	
protected:
	ChessColor color;
	PieceType type;
};


#endif