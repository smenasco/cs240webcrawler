/*
 *  MoveHistory.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "MoveHistory.h"

using namespace std;

MoveHistory::MoveHistory(){
	
}
MoveHistory::~MoveHistory(){
	
}
void MoveHistory::Push( const Move & move){
	moveStack.push_back(move);
}
void MoveHistory::Pop(){
	moveStack.pop_back();
}
const Move& MoveHistory::Bottom () const{
	return moveStack.front();
}
const Move& MoveHistory::Top () const{
	return moveStack.back();
}
bool MoveHistory::IsEmpty()const{
	return moveStack.empty();
}
const std::deque<Move> & MoveHistory::GetMoveStack(){
	return moveStack;
}