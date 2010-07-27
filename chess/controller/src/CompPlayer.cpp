/*
 *  CompPlayer.cpp
 *  project2
 *
 *  Created by Sam on 7/26/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "CompPlayer.h"

using namespace std;

CompPlayer::CompPlayer(GameBoard * board,PieceColor color): ChessPlayer(board,color){
	
}

bool CompPlayer::on_CellSelected(int row, int col){
	return false;
}

bool CompPlayer::on_TimerEvent(){
	return false;
}