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
bool SaveLoadGame::IsValidChessFile(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		std::string tokenval = StringUtil::ToLowerCopy(token.GetValue());
		if (tokenval == "chessgame" && type == TAG_START){
			return true;
		}
	}
	return false;
}

PieceColor SaveLoadGame::Load(std::string filename){
	
	
	lasttomove = BLACK;
	//need to initialize HTML parser and begin tokenizing state-machine
	if (filename.substr(0,7) != "file://"){
		filename = "file://" + filename;
	}
	cout <<  filename << endl;

	try{
		
		stream = new URLInputStream(filename);
		tokenizer = new HTMLTokenizer(stream);
		stream->Close();
		if (IsValidChessFile()){
			board->Clear();
			board->NewBoard();
			moves->Reset();
			ParseBoard();
			ParseMoveHistory();
		}else
			throw FileException(std::string("This file is not a valid chess file! ") + filename);

		CleanLoad();
	}
	catch (std::exception &e) {
		std::cout << "Load: Exception Occurred:" << e.what() << std::endl;
		CleanLoad();
		lasttomove = (PieceColor)0;
	}
	catch (CS240Exception &e) {
		std::cout << "Load: CS240Exception Occurred:" << e.GetMessage() << std::endl;
		lasttomove = (PieceColor)0;
		CleanLoad();
	}
	catch (...) {
		std::cout << "Load: Unknown Exception Occurred" << std::endl;
		lasttomove = (PieceColor)0;
		CleanLoad();
	}
	return lasttomove;
}

void SaveLoadGame::ParseBoard(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		ChessPiece *p;
		std::string tokenval = StringUtil::ToLowerCopy(token.GetValue());
		if (tokenval == "board" && type == TAG_START){
			//cout << "We are in the board\n";
		}
		if (tokenval == "piece"){
			p = ParsePieceBoard(token);
			if (p == NULL){
				//cout << "We have a problem\n";
			}
		}
		if (tokenval == "board" && type == TAG_END){
			//cout << "we should leave  the board\n";
			return;
		}
		
		
	}
}

ChessPiece * SaveLoadGame::ParsePieceHistory(HTMLToken token){
	ChessPiece * piece;
	PieceType type;
	PieceColor color;
	int row;
	int col;
	
	
	
	if (token.AttributeExists("color")){
		string s = token.GetAttribute("color");
		if (s == "white")
			color = WHITE;
		if (s == "black")
			color = BLACK;
		//cout << color;
		//std::cout << "Found color: " << token.GetAttribute("color") << std::endl;
	}
	
	if (token.AttributeExists("column")){
		col = atoi((token.GetAttribute("column")).c_str());
		//cout << "Found col: " << col <<":"<<token.GetAttribute("column") << endl;	
	}
	
	if (token.AttributeExists("row")){
		row = atoi((token.GetAttribute("row")).c_str());
		//cout << "Found row: " << row <<":"<<token.GetAttribute("row") << endl;
	}
	
	if (token.AttributeExists("type")){
		string s = token.GetAttribute("type");
		if (s == "bishop")
			type = BISHOP;
		if (s == "pawn")
			type = PAWN;
		if (s == "knight")
			type = KNIGHT;
		if (s == "rook")
			type = ROOK;
		if (s == "king")
			type = KING;
		if (s == "queen")
			type = QUEEN;
		//cout <<type;
		//std::cout << "Found type: " << token.GetAttribute("type") << std::endl;
	}
	
	switch (type){
		case PAWN:
			piece = new Pawn(row,col,color);
			break;
		case ROOK:
			piece = new Rook(row,col,color);
			break;
		case KNIGHT:
			piece = new Knight(row,col,color);
			break;
		case BISHOP:
			piece = new Bishop(row,col,color);
			break;
		case KING:
			piece = new King(row,col,color);
			break;
		case QUEEN:
			piece = new Queen(row,col,color);
			break;
	}
	return piece;
}

ChessPiece * SaveLoadGame::ParsePieceBoard(HTMLToken token){
	Square * s;
	PieceType type;
	PieceColor color;
	int row;
	int col;
	
	if (token.AttributeExists("type")){
		string s = token.GetAttribute("type");
		if (s == "bishop")
			type = BISHOP;
		if (s == "pawn")
			type = PAWN;
		if (s == "knight")
			type = KNIGHT;
		if (s == "rook")
			type = ROOK;
		if (s == "king")
			type = KING;
		if (s == "queen")
			type = QUEEN;
		//cout <<type;
		//std::cout << "Found type: " << token.GetAttribute("type") << std::endl;
	}
	
	if (token.AttributeExists("color")){
		string s = token.GetAttribute("color");
		if (s == "white")
			color = WHITE;
		if (s == "black")
			color = BLACK;
		//cout << color;
		//std::cout << "Found color: " << token.GetAttribute("color") << std::endl;
	}
	
	if (token.AttributeExists("column")){
		col = atoi((token.GetAttribute("column")).c_str());
		//cout << "Found col: " << col <<":"<<token.GetAttribute("column") << endl;	
	}
	
	if (token.AttributeExists("row")){
		row = atoi((token.GetAttribute("row")).c_str());
		//cout << "Found row: " << row <<":"<<token.GetAttribute("row") << endl;
	}
	
	s = board->GetSquare(row,col);
	s->SetPiece(row,col,color,type);
	
	return board->GetPiece(row,col);
}
void SaveLoadGame::ParseMoveHistory(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
	
		std::string tokenval = StringUtil::ToLowerCopy(token.GetValue());
		
		if (tokenval == "history" && type == TAG_START){
			//cout << "We are in the history\n";
		}
		if (tokenval == "move" && type == TAG_START){
			ParseMove(token);
		}
		if (tokenval == "history" && type == TAG_END){
			//cout << "we should leave  the history\n";
			return;
		}
		
		
	}
}

void SaveLoadGame::ParseMove(HTMLToken token){
	int count = 0;
	Move m;
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		ChessPiece * p= NULL;
		std::string tokenval = StringUtil::ToLowerCopy(token.GetValue());

		
		
		if (tokenval == "piece"){
			count++;
			if (count == 1){
				p = ParsePieceHistory(token);
				lasttomove = p->GetColor();
				m.SetMoveFrom(p);
			}
			if (count == 2) {
				p = ParsePieceHistory(token);
				m.SetMoveTo(p);
			}
			if (count == 3) {
				p = ParsePieceHistory(token);
				m.SetKill(p);
			}
		}
		if (p != NULL)
			delete p;
		
		if (tokenval == "move" && type == TAG_END){
			moves->Push(m);
			//cout << "we should leave  the move\n";
			return;
		}
		
		
	}
	

}
