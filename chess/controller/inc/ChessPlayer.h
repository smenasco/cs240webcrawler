#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

/**
 * The ChessPlayer class provides an interface for a ChessController implementation to interact
 * with the player through, regardless of whether the player is a human or a computer.
 */

#include "GameBoard.h"
#include "GameInfo.h"
#include "Square.h"
#include "ChessPiece.h"
#include "BoardPosition.h"
#include "ChessView.h"
#include <set>


class ChessPlayer {
public: //methods
	
	void Init();
	
	ChessPlayer(GameBoard * board, PieceColor color);
	
	void SetView(ChessView * view);
	void HighlightValidMoves(int row, int col);
	bool IsInCheck();
	bool IsCheckMate();
	/**
	 * Indicate to the player that the user clicked on the given
	 * row and column with the mouse.
	 */
	virtual bool on_CellSelected(int row, int col) = 0;

	/**
	 * Handle when the timeout duration has passed.
	 */
	virtual bool on_TimerEvent() = 0;
protected:
	ChessView * view;
	GameBoard * board;
	PieceColor color;
	
	BoardPosition king;
	ChessPiece * movingPiece;
	Square * movingSquare;
	std::set<BoardPosition> validMoves;
};

#endif
