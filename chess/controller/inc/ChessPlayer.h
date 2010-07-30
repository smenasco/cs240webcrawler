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
#include "Move.h"
#include "MoveHistory.h"
#include <set>


class ChessPlayer {
public: //methods
	
	//Clears the highlights from the board
	//And starts the turn over
	void Init();
	
	//Constructs a new Chess Player whether it be 
	//Human or Computer
	ChessPlayer(GameBoard * board, PieceColor color);
	
	//Tell ChessPlayer where to put moves 
	void SetMoveHistory(MoveHistory * m);
	
	//Just so we can highlight moves on the chess
	//board
	void SetView(ChessView * view);
	
	//Highlight valid moves of the selected piece
	void HighlightValidMoves(int row, int col);
	
	//for the controller to know whether or not 
	//the current player is in check
	bool IsInCheck();
	
	//for the controller to know whether or not
	//the current player is in check
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
	MoveHistory * moves;
	
	BoardPosition king;
	ChessPiece * movingPiece;
	Square * movingSquare;
	std::set<BoardPosition> validMoves;
	
};

#endif
