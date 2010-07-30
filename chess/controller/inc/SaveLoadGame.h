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
#include "HTMLTokenizer.h"
#include "HTMLTOken.h"
#include <string>

//Handles the saving and loading to and from valid xml
//uses the HTML tokenizer to load and homebrew xml writer
//to save
class SaveLoadGame {
public:
	SaveLoadGame(GameBoard * board, MoveHistory * moves);
	~SaveLoadGame();
	//saves the game using the current board and move history
	//to filename
	void Save(std::string filename);
	
	//loads the game using the filename and sets up the move history
	//and chess board
	void Load(std::string filename);
private:
	GameBoard * board;
	MoveHistory * moves;
};
#endif