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

//inherits from Chessplayer 
//implements computer player moves
class CompPlayer : public ChessPlayer {
public:
	
	CompPlayer(GameBoard * board, PieceColor color);
	~CompPlayer();
	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse.  To be ignored for computer player
	 */
	bool on_CellSelected(int row, int col);
	
	void Init();
	/**
	 * Handle when the timeout duration has passed.
	 * implements the move piece for computer player
	 */
	bool on_TimerEvent();
	
private:
	int row;
	int col;
};


#endif