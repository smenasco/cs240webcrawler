/*
 *  Controller.cpp
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "Controller.h"
#include "ChessGuiDefines.h"


using namespace std;
//! No arg Constructor
Controller::Controller(GameType mode):mode(mode){
	savefile = "";
	view = NULL;
	board = new GameBoard();
	white = NULL;
	black = NULL;
	moves = NULL;
	saveload = new SaveLoadGame(board);
}

//! Destructor
//! Maher-shalal-hash-baz 
Controller::~Controller(){
	delete white;
	delete black;
	delete board;
	delete moves;
}

void Controller::NewGame(){
	//Clear errythang ie. MoveHistory
	UnHighlightSquares();	
	board->Reset();
	
	
	ClearGame();
	
	//view->SetStatusBar("This is the status bar");
	view->ClearMessageArea();
	view->WriteMessageArea("New Game!\n");
	view->WriteMessageArea("White's turn!\n");
	//mode = hh;
	switch (mode){
		case hh:
			view->SetTopLabel("Human");
			view->SetBottomLabel("Human");
			white = new HumanPlayer(board, WHITE);
			black = new HumanPlayer(board,BLACK);
			break;
		case hc:
			view->SetTopLabel("Computer");
			view->SetBottomLabel("Human");
			white = new HumanPlayer(board,WHITE);
			black = new CompPlayer(board,BLACK);
			break;
		case ch:
			view->SetTopLabel("Human");
			view->SetBottomLabel("Computer");
			white = new CompPlayer(board,WHITE);
			black = new HumanPlayer(board,BLACK);
			break;
		case cc:
			view->SetTopLabel("Computer");
			view->SetBottomLabel("Computer");
			white = new CompPlayer(board,WHITE);
			black = new CompPlayer(board,BLACK);
			break;
	}
	
	white->SetView(view);
	white->SetMoveHistory(moves);
	black->SetView(view);
	black->SetMoveHistory(moves);	
	saveload->SetMoveHistory(moves);
	currentPlayer = white;
	RefreshDisplay();
	
}
void Controller::RefreshDisplay(){
	for (int i = 0; i < 8;i++){
		for (int j = 0; j< 8;j++){
			ChessPiece * p = board->GetSquare(i,j)->GetPiece();
			if (p!= NULL){
				PieceColor color = p->GetColor();
				PieceType type = p->GetType();
				switch (type){
					case ROOK:
						if (color == WHITE){
							view->PlacePiece(i,j, W_ROOK);
						}else
							view->PlacePiece(i,j, B_ROOK);
						break;
					case QUEEN:
						if (color == WHITE){
							view->PlacePiece(i,j, W_QUEEN);
						}else
							view->PlacePiece(i,j, B_QUEEN);
						break;
					case PAWN:
						if (color == WHITE){
							view->PlacePiece(i,j, W_PAWN);
						}else
							view->PlacePiece(i,j, B_PAWN);
						break;
					case KING:
						if (color == WHITE){
							view->PlacePiece(i,j, W_KING);
						}else
							view->PlacePiece(i,j, B_KING);
						break;
					case KNIGHT:
						if (color == WHITE){
							view->PlacePiece(i,j, W_KNIGHT);
						}else
							view->PlacePiece(i,j, B_KNIGHT);
						break;
					case BISHOP:
						if (color == WHITE){
							view->PlacePiece(i,j, W_BISHOP);
						}else
							view->PlacePiece(i,j, B_BISHOP);
						break;
						
				}
			} else
				view->ClearPiece(i,j);
			
		}
	}
}
void Controller::ClearGame(){
	if (white != NULL)
		delete white;
	if (black != NULL)
		delete black;
	if (moves != NULL)
		delete moves;
	moves = new MoveHistory();
}
/**
 * Indicate to the player that the user clicked on the given
 * row and column with the mouse.
 */
void Controller::on_CellSelected(int row, int col, int button){
	/*
	 Each square of the chess board is reffered to in the GUI code as a cell.
	 This Function is called whenever the uses clicks and releases the mous button over
	 a cell without initiating a drag. Row and Column coordinates begin in the top left corner.
	 The button paramter tells which mouse button was clicked
	 (1 for left, 2 for middle, 3 for right).
	 You do not need to worry about which button was used to complete the project.
	 */
	if (currentPlayer->IsCheckMate()){
		//dont do anything
	} else if (currentPlayer->on_CellSelected(row,col)){
		ChangePlayer();
		RefreshDisplay();
	}
	
	
}

void Controller::ChangePlayer(){
	if (currentPlayer == white){
		currentPlayer = black;
		view->ClearMessageArea();
		view->WriteMessageArea("Black's turn\n");
	}
	else {
		currentPlayer = white;
		view->ClearMessageArea();
		view->WriteMessageArea("White's turn\n");
	}
	CheckGameState();

	
}

void Controller::CheckGameState(){
	if (currentPlayer->IsCheckMate() && currentPlayer->IsInCheck()){
		view->WriteMessageArea("CHECKMATE!\n");
	}
	else if (currentPlayer->IsCheckMate() && !currentPlayer->IsInCheck()){
		view->WriteMessageArea("STALEMATE!\n");
	} else if (currentPlayer->IsInCheck())
		view->WriteMessageArea("CHECK!\n");
}


///@param row where drag began
///@param col where drag began
void Controller::on_DragStart(int row,int col){
	/*
	 When a drag is initiated, this function will be called instead of on_CellSelected().
	 The paramaters row and col are the coordinates of the cell where the drag was initiated.
	 All three buttons may initiate the drag, but for our purposes can be treated
	 the same and so	that paramater is not included.
	 
	 if (board != NULL){
	 movingPiece = board->GetSquare(row,col)->MovePiece();
	 //board->GetSquare(row,col)->SetPiece(NULL);
	 }
	 */
	
}

///@param row where drag ended
///@param col where drag ended
///@return true if the drag resulted in a successful drop
bool Controller::on_DragEnd(int row,int col){
	/*
	 Same as on_DragStart() except the coordinates represent the ending cell of
	 the drag. If the drag terminates off the playing board, this will be called with
	 the initial coordinates of the drag.
	 
	 if (movingPiece == NULL){
	 Init();
	 return false;
	 } else {
	 Square * s = board->GetSquare(row,col);
	 //ChessPiece * p = board->GetSquare(row,col)->GetPiece();
	 movingPiece->SetBoardPosition(row,col);
	 s->SetPiece(movingPiece);
	 
	 }
	 RefreshDisplay();
	 Init();
	 */
	//by convention, this should return a boolean value indicating if the drag was accepted or not.
	return true;
}

/**
 * Handle when the user selected the new game button.
 */
void Controller::on_NewGame(){
	//Possibly ask to save the game
	//ClearGame();
	NewGame();
	
}

/**
 * Handle when the user selected the save game button.
 */
void Controller::on_SaveGame(){
	if (savefile == "")
		savefile = view->SelectSaveFile();
	saveload->Save(savefile);
}

/**
 * Handle when the user selected the save game as button.
 */
void Controller::on_SaveGameAs(){
	savefile = view->SelectSaveFile();
	saveload->Save(savefile);
}

/**
 * Handle when the user selected the load game button.
 */
void Controller::on_LoadGame(){
	string loadfile = view->SelectLoadFile();
	if (loadfile.empty())
		return;
	
	PieceColor c = saveload->Load(loadfile);
	if (c == WHITE){
		if (currentPlayer == white)
			ChangePlayer();
	}else if (c == BLACK) {
		if (currentPlayer == black)
			ChangePlayer();
	}
	CheckGameState();
	
	black->Init();
	white->Init();
	UnHighlightSquares();	
	RefreshDisplay();

}

void Controller::UnHighlightSquares(){
	for (int i = 0; i < 8;i++){
		for (int j=0;j < 8;j++){
			view->UnHighlightSquare(i,j);
		}
	}
}
/**
 * Handle when the user selected the undo move button.
 */
void Controller::on_UndoMove(){
	Move m;
	if (!moves->IsEmpty()){
		int frow, fcol, trow, tcol;
		
		ChessPiece * p;
		Square * from;
		Square * to;
		
		m = moves->Top();
		
		
		frow = m.GetRow(MOVEFROM);
		fcol = m.GetCol(MOVEFROM);
		trow = m.GetRow(MOVETO);
		tcol = m.GetCol(MOVETO);
		from = board->GetSquare(frow,fcol);
		to = board->GetSquare(trow,tcol);
		p = to->MovePiece();
		p->SetBoardPosition(frow,fcol);
		from->SetPiece(p);
		if (m.GetKill() != ""){
			to->SetPiece(trow, tcol,m.GetColor(KILL), m.GetType(KILL));
		}
		moves->Pop();
		currentPlayer->Init();
		ChangePlayer();
		UnHighlightSquares();
	}

	RefreshDisplay();
}

/**
 * Handle when the user selects to quit the game, either through the
 * quit button, the close X button, or the file menu.
 */
void Controller::on_QuitGame(){
	/*It is not required to implement this function*/
	
	/*
	 Called when someone selects 'Quit' from the toolbar,
	 'Game' menu, presses 'Ctrl-Q', or closes the window.<br>
	 
	 on_QuitGame() does not need to be implemented to fulfill the
	 requirements of the project, but is available for your
	 use.
	 */
	//Needs to call ClearGame() and clean up errythang
}

/**
 * Handle when a timer event has been signaled.
 */
void Controller::on_TimerEvent(){
	
	if (currentPlayer->IsCheckMate()){
		//dont do anything
	} else if (currentPlayer->on_TimerEvent()){
		ChangePlayer();
		RefreshDisplay();
	}
	
}

/**
 * Set the view that this Controller will tell to update and make changes.
 */
void Controller::SetView(ChessView* v){
	view = v;
	
}
