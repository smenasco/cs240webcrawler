/*
 *  SaveLoadGame.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "SaveLoadGame.h"

using namespace std;

SaveLoadGame::SaveLoadGame(GameBoard * board):
board(board),stream(NULL),tokenizer(NULL){
	
}

SaveLoadGame::~SaveLoadGame(){
	CleanLoad();
}

void SaveLoadGame::SetMoveHistory(MoveHistory * moves){
	this->moves = moves;
}

string SaveLoadGame::PieceToString(ChessPiece * p){
	string type;
	string color;
	string row;
	string col;
	switch (p->GetType()) {
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
	
	switch (p->GetColor()){
		case WHITE:
			color= "white";
			break;
		case BLACK:
			color= "black";
			break;
	}
	
	row = IntToString((p->GetBoardPosition()).GetRow());
	col = IntToString((p->GetBoardPosition()).GetCol());
	string s = "<piece type=\""+ type + "\" color=\"" + color+ "\" column=\""+ col+"\" row=\""+row+"\"/>";
	return s;
}

string SaveLoadGame::IntToString(int i){
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

void SaveLoadGame::Save(std::string filename){
	deque<Move> moveStack = moves->GetMoveStack();
	ChessPiece * p;
	Square * s;
	ofstream output;
	try {
		
		output.open(filename.c_str());
		
		output << "<chessgame>" << endl;
		output << "\t<board>" << endl;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				s= board->GetSquare(i,j);
				p = s->GetPiece();
				if (p != NULL){
					string piece = PieceToString(p);
					output << "\t\t" <<piece << endl;
				}
			}
		}
		output << "\t</board>" << endl;		
		output << "\t<history>" << endl;
		deque<Move>::iterator it;
		for (it = moveStack.begin(); it != moveStack.end();it++){
			output << "\t\t<move>" << endl;
			output << "\t\t\t" <<(*it).GetMoveFrom() << endl;
			output << "\t\t\t" <<(*it).GetMoveTo() << endl;
			if ((*it).GetKill() != "")
				output << "\t\t\t" <<(*it).GetKill() << endl;
			output << "\t\t</move>" << endl;
		}
		output << "\t</history>" << endl;
		output << "</chessgame>" << endl;
		
		
		output.close();
	}
	catch (std::exception &e) {
		std::cout << "Save: Exception Occurred:" << e.what() << std::endl;		
	}
	catch (CS240Exception &e) {
		std::cout << "Save: Exception Occurred:" << e.GetMessage() << std::endl;
	}
	catch (...) {
	}
	
}
void SaveLoadGame::CleanLoad(){
	if (stream != NULL)
		delete stream;
	if (tokenizer != NULL)
		delete tokenizer;
	stream = NULL;
	tokenizer = NULL;
}
void SaveLoadGame::Load(std::string filename){
	board->Clear();
	board->NewBoard();
	
	//need to initialize HTML parser and begin tokenizing state-machine
	
	
	try{
		
		stream = new URLInputStream(filename);
		tokenizer = new HTMLTokenizer(stream);
		//Handle redirections (Find out where we redirected to)
		//std::cout << "=======================================" << std::endl;
		//std::cout << "Actual Location: " << path << std::endl;
		//This is where the actual parsing beings

		CleanLoad();
	}
	catch (std::exception &e) {
		std::cout << "Load: Exception Occurred:" << e.what() << std::endl;
		CleanLoad();
	}
	catch (CS240Exception &e) {
		std::cout << "Load: CS240Exception Occurred:" << e.GetMessage() << std::endl;
		CleanLoad();
	}
	catch (...) {
		std::cout << "Load: Unknown Exception Occurred" << std::endl;
		CleanLoad();
	}
	
	//set new pieces on squares
	//construct move history using HTMLparser with xml
}

void SaveLoadGame::ParseBoard(){
}
void SaveLoadGame::ParsePiece(){
	
}
void SaveLoadGame::ParseMoveHistory(){
	
}