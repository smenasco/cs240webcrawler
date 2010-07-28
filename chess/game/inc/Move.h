#ifndef MOVE_H
#define MOVE_H
/*
 *  Move.h
 *  project2
 *
 *  Created by Sam on 7/28/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include <string>

class Move{
public:
	Move();
	void SetMoveFrom();
	void SetMoveTo();
	void SetKill();
private:
	std::string movefrom;
	std::string moveto;
	std::string kill;
};


#endif