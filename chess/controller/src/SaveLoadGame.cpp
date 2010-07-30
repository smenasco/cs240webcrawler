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
	//HANDLE ALL READ WRITE EXCEPTIONS
	/* iterate throug the current gameboard
	  save location of all the pieces to xml
	 iterate through the move history
	 write all the moves in xml
	 */
}

void SaveLoadGame::Load(std::string filename){
	//HANDLE ALL READ WRITE EXCEPTIONS
	//USE HTMLParser to read in piece loaction 
	//and move history
	board->Clear();
	board->NewBoard();
	//set new pieces on squares as parsed from xml
	//construct move history using HTMLparser with xml
	//check who should be the current player based on who
	//the last move is in move history
}