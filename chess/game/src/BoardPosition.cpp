/*
 *  BoardPosition.cpp
 *  project2
 *
 *  Created by Sam on 7/23/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "BoardPosition.h"

BoardPosition::BoardPosition(){
	
}
BoardPosition::BoardPosition(int row, int col):row(row), col(col){
	
}
BoardPosition::~BoardPosition(){
	
}
const int BoardPosition::GetRow() const {
	return row;
}
const int BoardPosition::GetColumn() const {
	return col;
}
void BoardPosition::SetRow(int r){
	row = r;
}
void BoardPosition::SetCol(int c){
	col = c;
}