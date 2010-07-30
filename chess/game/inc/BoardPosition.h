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
	
	//empty constructor.
	BoardPosition();
	
	//constructor. create new board positon with initial values.
	BoardPosition(int row, int col);
	
	//destructor
	~BoardPosition();
	
	//copy constructor
	BoardPosition(const BoardPosition & other);

	//standard operator overloads for use in STL
	BoardPosition & operator =(const BoardPosition & other);
	bool operator ==(const BoardPosition & other) const;
	bool operator !=(const BoardPosition & other) const;
	bool operator  <(const BoardPosition & other) const;
	//-------------------------------------------------
	
	
	//standard getters and setters
	int GetRow()const ;
	int GetCol() const;
	void SetRow(int r);
	void SetCol(int c);
	//----------------

private:
	void Init(int row, int col);
	int row;
	int col;
};

#endif