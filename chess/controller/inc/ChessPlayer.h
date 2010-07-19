#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include "ChessView.h"
#include "ChessModel.h"

/**
 * The ChessPlayer class provides an interface for a ChessView object to interact
 * with the player through, regardless of whether the player is a human or a computer.
 */
class ChessPlayer
{
public: //methods
	/**
	 * ChessPlayer constructor that takes a pointer to a ChessView interface
	 * and a ChessModel object.
	 */
	ChessPlayer(ChessView* view, ChessModel* model);
	/**
	 * Standard ChessPlayer destructor.
	 */
	virtual ~ChessPlayer();
	
	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse.
	 */
	virtual void on_CellSelected(int row, int col, int button);

	/**
	 * Handle when the user selected the new game button.
	 */
	virtual void on_NewGame();

	/**
	 * Handle when the user selected the save game button.
	 */
	virtual void on_SaveGame();

	/**
	 * Handle when the user selected the save game as button.
	 */
	virtual void on_SaveGameAs();

	/**
	 * Handle when the user selected the load game button.
	 */
	virtual void on_LoadGame();

	/**
	 * Handle when the user selected the undo move button.
	 */
	virtual void on_UndoMove();
		
	/**
	 * Handle when a tenth of a second has passed.
	 */
	virtual void on_TenthOfASecond();
	
protected:/**
	 * A pointer to the current ChessView object.
	 */
	ChessView* view;
};

#endif
