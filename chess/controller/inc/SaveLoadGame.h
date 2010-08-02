#ifndef SAVELOADGAME_H
#define SAVELOADGAME_H
/*
 *  SaveLoadGame.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */


#include "Square.h"
#include "GameBoard.h"
#include "BoardPosition.h"
#include "ChessPiece.h"
#include "MoveHistory.h"
#include "Move.h"
#include "CS240Exception.h"
#include "HTMLTokenizer.h"
#include "InputStream.h"
#include "URLInputStream.h"
#include <string>
#include <deque>
#include <iostream>
#include <fstream>

//Handles the saving and loading to and from valid xml
//uses the HTML tokenizer to load and homebrew xml writer
//to save
class SaveLoadGame {
public:
	SaveLoadGame(GameBoard * board);
	~SaveLoadGame();
	//saves the game using the current board and move history
	//to filename
	void Save(std::string filename);

	//loads the game using the filename and sets up the move history
	//and chess board
	void Load(std::string filename);
	void SetMoveHistory(MoveHistory * moves);
private:
	GameBoard * board;
	MoveHistory * moves;
	URLInputStream * stream;	//!< the stream to load the url from
	HTMLTokenizer *tokenizer;	
	
	std::string PieceToString(ChessPiece * p);
	std::string IntToString(int i);
	bool IsValidChessFile();
	void CleanLoad();
	void ParseBoard();
	void ParsePiece();
	void ParseMoveHistory();
};
#endif
