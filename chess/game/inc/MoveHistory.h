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


#include <stack>
#include "Move.h"

class MoveHistory {
public:
	MoveHistory();
	~MoveHistory();
private:
	std::stack<Move> moveStack;
};




#endif