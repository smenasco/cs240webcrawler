#ifndef MOVEHISTORY_H
#define MOVEHISTORY_H
/*
 *  MoveHistory.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */


#include <deque>
#include "Move.h"

//Stores a stack of moves
//write when a move is created 
//by chessplayers and load 
//read for undo and save

class MoveHistory {
	friend class SaveLoadGame;
public:
	MoveHistory();
	~MoveHistory();
	void Push( const Move & move);
	void Pop();
	const Move& Top () const;
	const Move& Bottom () const;
	bool IsEmpty()const;
	
private:
	std::deque<Move> moveStack;
	
	//private function available only to SaveLoadGame friend class
	const std::deque<Move> & GetMoveStack();
};





#endif