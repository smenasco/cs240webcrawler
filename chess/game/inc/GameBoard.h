#ifndef GAMEBOARD_H
#define GAMEBOARD_H
/*
 *  GameBoard.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include "ChessPiece.h"
#include "Square.h"
#include <vector>


class GameBoard {
public:
	GameBoard();
	~GameBoard();
	Square * GetSquare(int row, int col);
private:
	std::vector< std::vector<Square*> > board;
};

#endif