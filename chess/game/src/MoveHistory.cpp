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
	moveStack.push(move);
}
void MoveHistory::Pop(){
	moveStack.pop();
}
const Move& MoveHistory::Top () const{
	return moveStack.top();
}
bool MoveHistory::IsEmpty()const{
	return moveStack.empty();
}