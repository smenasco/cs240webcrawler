/*
 *  Move.cpp
 *  project2
 *
 *  Created by Sam on 7/28/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Move.h"

using namespace std;

Move::Move():kill(""){
	
}


void Move::SetParams(ChessPiece * piece){

	switch (piece->GetType()) {
		case PAWN:
			type = "pawn";
			break;
		case ROOK:
			type = "rook";
			break;
		case BISHOP:
			type = "bishop";
			break;
		case KNIGHT:
			type = "knight";
			break;
		case QUEEN:
			type = "queen";
			break;
		case KING:
			type = "king";
			break;
	}
	
	switch (piece->GetColor()){
		case WHITE:
			color= "white";
			break;
		case BLACK:
			color= "black";
			break;
	}
	
	row = IntToString((piece->GetBoardPosition()).GetRow());
	col = IntToString((piece->GetBoardPosition()).GetCol());
}


string Move::IntToString(int i){
	string s = "";
	switch (i) {
		case 0:
			s = "0";
			break;
		case 1:
			s = "1";
			break;
		case 2:
			s = "2";
			break;
		case 3:
			s = "3";
			break;
		case 4:
			s = "4";
			break;
		case 5:
			s = "5";
			break;
		case 6:
			s = "6";
			break;
		case 7:
			s = "7";
			break;
		default:
			s="invalid row/col";
			break;
			
	} 
	return s;
}
void Move::WriteString(int which){
	string s = "";
	s+="<piece type=\"";
	s+=type;
	s+="\" color=\"";
	s+=color;
	s+="\" column=\"";
	s+=col;
	s+="\" row=\"";
	s+=row;
	s+="\"/>";
	switch (which){
		case 1:
			movefrom = s;
			break;
		case 2:
			moveto = s;
			break;
		case 3:
			kill = s;
			break;
	}
}
//  <piece type="bishop" color="white" column="6" row="3"/>

bool Move::operator ==(const Move & other) const{
	return ((movefrom == other.GetMoveFrom()) &&
			(moveto == other.GetMoveTo()) && 
			(kill == other.GetKill()) );
}
void Move::SetMoveFrom(ChessPiece * piece){
	SetParams(piece);
	WriteString(1);
	
	
}
void Move::SetMoveTo(ChessPiece * piece){
	SetParams(piece);
	WriteString(2);
	
}

void Move::SetKill(ChessPiece * piece){
	SetParams(piece);
	WriteString(3);
	
}

const std::string & Move::GetMoveFrom()const {
	return movefrom;
}

const std::string & Move::GetMoveTo() const {
	return moveto;
}
const std::string & Move::GetKill() const {
	return kill;
}


