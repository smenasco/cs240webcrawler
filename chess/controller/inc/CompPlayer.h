#ifndef COMPPLAYER_H
#define COMPPLAYER_H

/*
 *  CompPlayer.h
 *  project2
 *
 *  Created by Sam on 7/26/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "ChessPlayer.h"
#include "GameBoard.h"

class CompPlayer : public ChessPlayer {
public:
	
	CompPlayer(GameBoard * board, PieceColor color, MoveHistory * moves);
	~CompPlayer();
	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse.
	 */
	bool on_CellSelected(int row, int col);
	
	/**
	 * Handle when the timeout duration has passed.
	 */
	bool on_TimerEvent();
	
private:
	int row;
	int col;
};


#endif