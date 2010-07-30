#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

/*
 *  HumanPlayer.h
 *  project2
 *
 *  Created by Sam on 7/26/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include "ChessPlayer.h"
#include "GameBoard.h"


class HumanPlayer : public ChessPlayer {
public:
	HumanPlayer(GameBoard * board, PieceColor color);
	~HumanPlayer();
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
	
};

#endif