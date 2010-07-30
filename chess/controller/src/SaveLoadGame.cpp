/*
 *  SaveLoadGame.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "SaveLoadGame.h"

using namespace std;

SaveLoadGame::SaveLoadGame(GameBoard * board, MoveHistory * moves):
							board(board),moves(moves){
	
}

SaveLoadGame::~SaveLoadGame(){
	
}

void SaveLoadGame::Save(std::string filename){
	
}

void SaveLoadGame::Load(std::string filename){
	board->Clear();
	board->NewBoard();
	//set new pieces on squares
	//construct move history using HTMLparser with xml
}