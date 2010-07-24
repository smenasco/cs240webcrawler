#ifndef BOARD_POSITION_H
#define BOARD_POSITION_H
/*
 *  BoardPosition.h
 *  project2
 *
 *  Created by Sam on 7/23/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

class BoardPosition {
public:
	BoardPosition();
	BoardPosition(int row, int col);
	~BoardPosition();
	const int GetRow()const ;
	const int GetColumn() const;
	void SetRow(int r);
	void SetCol(int c);
private:
	int row;
	int col;
};

#endif