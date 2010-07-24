#ifndef CONTROLLER_H
#define CONTROLLER_H
/*
 *  Controller.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */


#include "ChessView.h"
#include "ChessController.h"
#include "GameBoard.h"
#include "Square.h"
#include "ChessPiece.h"

class Controller : public ChessController {
public:
	
	//! No arg Constructor
	Controller();
	
	//! Destructor
	//!  Maher-shalal-hash-baz 
	~Controller();
	
	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse.
	 */
	void on_CellSelected(int row, int col, int button);
	
	///@param row where drag began
	///@param col where drag began
	void on_DragStart(int row,int col);
	
	///@param row where drag ended
	///@param col where drag ended
	///@return true if the drag resulted in a successful drop
	bool on_DragEnd(int row,int col);
	
	/**
	 * Handle when the user selected the new game button.
	 */
	void on_NewGame();
	
	/**
	 * Handle when the user selected the save game button.
	 */
	void on_SaveGame();
	
	/**
	 * Handle when the user selected the save game as button.
	 */
	void on_SaveGameAs();
	
	/**
	 * Handle when the user selected the load game button.
	 */
	void on_LoadGame();
	
	/**
	 * Handle when the user selected the undo move button.
	 */
	void on_UndoMove();
	
	/**
	 * Handle when the user selects to quit the game, either through the
	 * quit button, the close X button, or the file menu.
	 */
	void on_QuitGame();
	
	/**
	 * Handle when a timer event has been signaled.
	 */
	void on_TimerEvent();
	
	/**
	 * Set the view that this Controller will tell to update and make changes.
	 */
	void SetView(ChessView* v);
protected:
	GameBoard * board;
	ChessView * view;
	ChessPiece * movingPiece;
	void NewGame();
	void ClearGame();
	void RefreshDisplay();
};

#endif
