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
#include "ChessPiece.h"
#include "GameInfo.h"
#include "BoardPosition.h"
#include <string>
#include <iostream>

class Move{
public:
	Move();
	~Move();
	void SetMoveFrom(ChessPiece * piece);
	void SetMoveTo(ChessPiece * piece);
	void SetKill(ChessPiece * piece);
	const std::string & GetMoveFrom()const ;
	const std::string & GetMoveTo()const ;
	const std::string & GetKill()const ;
	Move(const Move & other);
	Move & operator =(const Move & other);
	bool operator ==(const Move & other) const;

	
	PieceType GetType(MovePieceType move);
	PieceColor GetColor(MovePieceType move);
	int GetRow(MovePieceType move);
	int GetCol(MovePieceType move);

private:
	std::string movefrom;
	std::string moveto;
	std::string kill;
	std::string type;
	std::string color;
	std::string row;
	std::string col;
	
	//<piece type="bishop" color="white" column="6" row="3"/>
	PieceType fromtype;
	PieceColor fromcolor;
	int fromcol;
	int fromrow;
	
	PieceType totype;
	PieceColor tocolor;
	int tocol;
	int torow;
	
	PieceType killtype;
	PieceColor killcolor;
	int killcol;
	int killrow;

	void Copy(const Move & other);
	void SetParams(ChessPiece * piece, MovePieceType move);
	void WriteString(int which);
	std::string IntToString(int i);
};


#endif