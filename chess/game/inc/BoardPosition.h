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
	BoardPosition(const BoardPosition & other);
	BoardPosition & operator =(const BoardPosition & other);
	bool operator ==(const BoardPosition & other) const;
	bool operator !=(const BoardPosition & other) const;
	bool operator  <(const BoardPosition & other) const;
	int GetRow()const ;
	int GetCol() const;
	void SetRow(int r);
	void SetCol(int c);
private:
	void Init(int row, int col);
	int row;
	int col;
};

#endif