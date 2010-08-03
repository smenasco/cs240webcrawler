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

//inhereits from chessplayer 
//implements human player moves
class HumanPlayer : public ChessPlayer {
public:
	HumanPlayer(GameBoard * board, PieceColor color);
	~HumanPlayer();
	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse. Implements the move piece
	 */
	bool on_CellSelected(int row, int col);
	
	void Init();
	/**
	 * Handle when the timeout duration has passed.
	*  To be ignored for human player
	 */
	bool on_TimerEvent();
	
private:
	
};

#endif