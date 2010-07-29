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
	void SetMoveFrom(ChessPiece * piece);
	void SetMoveTo(ChessPiece * piece);
	void SetKill(ChessPiece * piece);
	const std::string & GetMoveFrom()const ;
	const std::string & GetMoveTo()const ;
	const std::string & GetKill()const ;
	bool operator ==(const Move & other) const;
	std::string IntToString(int i);
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
	PieceColor frommcolor;
	int fromcol;
	int fromrow;
	
	PieceType totype;
	PieceColor tomcolor;
	int tocol;
	int torow;
	
	PieceType killtype;
	PieceColor killmcolor;
	int killcol;
	int killrow;
	
	void SetParams(ChessPiece * piece);
	void WriteString(int which);
};


#endif