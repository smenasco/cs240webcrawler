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

class MoveHistory {
public:
	MoveHistory();
	~MoveHistory();
	void Push( const Move & move);
	void Pop();
	const Move& Top () const;
	bool IsEmpty()const;
private:
	std::deque<Move> moveStack;
};




#endif