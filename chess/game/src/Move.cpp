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
Move::~Move(){
	
}
void Move::Copy(const Move & other){
	movefrom=other.movefrom;
	moveto=other.moveto;
	kill=other.kill;
	type=other.type;
	color==other.color;
	row=other.row;
	col=other.col;
	
	//<piece type="bishop" color="white" column="6" row="3"/>
	fromtype=other.fromtype;
	fromcolor=other.fromcolor;
	fromcol=other.fromcol;
	fromrow=other.fromrow;
	
	
	totype=other.totype;
	tocolor=other.tocolor;
	tocol=other.tocol;
	torow=other.torow;
	
	killtype=other.killtype;
	killcolor=other.killcolor;
	killcol=other.killcol;
	killrow=other.killrow;
}
Move::Move(const Move & other){
	Copy(other);
}
Move & Move::operator =(const Move & other){	
	if (this != &other) {
		Copy(other);
	}
	return *this;
	
}


void Move::SetParams(ChessPiece * piece, MovePieceType move){
	switch (move){
		case MOVEFROM: 
			fromtype= piece->GetType();
			fromcolor= piece->GetColor();
			fromcol= (piece->GetBoardPosition()).GetCol();
			fromrow= (piece->GetBoardPosition()).GetRow();
			break;
		case MOVETO: 
			
			totype= piece->GetType();
			tocolor= piece->GetColor();
			tocol= (piece->GetBoardPosition()).GetCol();
			torow= (piece->GetBoardPosition()).GetRow();
			break;
		case KILL: 
			killtype= piece->GetType();
			killcolor= piece->GetColor();
			killcol= (piece->GetBoardPosition()).GetCol();
			killrow= (piece->GetBoardPosition()).GetRow();
			break;
			
	}
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

bool Move::operator<(const Move & other) const {
	return (movefrom < other.movefrom);
}

void Move::SetMoveFrom(ChessPiece * piece){
	SetParams(piece,MOVEFROM);
	WriteString(1);
	
	
}
void Move::SetMoveTo(ChessPiece * piece){
	SetParams(piece,MOVETO);
	WriteString(2);
	
}

void Move::SetKill(ChessPiece * piece){
	SetParams(piece,KILL);
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

PieceType Move::GetType(MovePieceType move){
	switch (move) {
		case MOVEFROM:
			return fromtype;
			break;
		case MOVETO:
			return totype;
			break;
		case KILL:
			return killtype;
			break;
	}
	return (PieceType)-8; //means invalid
}

PieceColor Move::GetColor(MovePieceType move){
	switch (move) {
		case MOVEFROM:
			return fromcolor;
			break;
		case MOVETO:
			return tocolor;
			break;
		case KILL:
			return killcolor;
			break;
	}
	return (PieceColor)-8; //means invalid
}

int Move::GetRow(MovePieceType move){
	switch (move) {
		case MOVEFROM:
			return fromrow;
			break;
		case MOVETO:
			return torow;
			break;
		case KILL:
			return killrow;
			break;
	}
	return -8; //means invalid
}

int Move::GetCol(MovePieceType move){
	switch (move) {
		case MOVEFROM:
			return fromcol;
			break;
		case MOVETO:
			return tocol;
			break;
		case KILL:
			return killcol;
			break;
	}
	return -8; //means invalid
}

