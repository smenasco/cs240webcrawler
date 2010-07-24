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

void BoardPosition::Init(int row,int col){
	this->row = row;
	this->col =col;

}

BoardPosition::BoardPosition(const BoardPosition & other) { 
	Init(other.row,other.col);
}

BoardPosition & BoardPosition::operator =(const BoardPosition & other){
	if (this != &other) {
		Init(other.row,other.col);
	}
	return *this;
}

bool BoardPosition::operator ==(const BoardPosition & other) const {
	if (row == other.row && col == other.col){
		return true;
	}else 
		return false;
}

bool BoardPosition::operator!=(const BoardPosition & other) const {
    return !(*this == other);
}

bool BoardPosition::operator<(const BoardPosition & other) const {
	if (row != other.row)
		return (row < other.row);
	else
		return (col < other.col);
		
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