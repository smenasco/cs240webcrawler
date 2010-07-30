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
#include <string>


class SaveLoadGame {
public:
	SaveLoadGame(GameBoard * board, MoveHistory * moves);
	~SaveLoadGame();
	void Save(std::string filename);
	void Load(std::string filename);
private:
	GameBoard * board;
	MoveHistory * moves;
};
#endif