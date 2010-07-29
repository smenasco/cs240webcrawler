#ifndef GAMEINFO_H
#define GAMEINFO_H
/*
 *  GameInfo.h
 *  project2
 *
 *  Created by Sam on 7/22/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
enum GameType{hh=1,	//Run the chess program in Human vs. Human mode.
		hc=2,			//Run the chess program in Human vs. Computer mode, 
					//where the Human player is the white team.
		ch=3,			//Run the chess program in Computer vs. Human mode,
					//where the Computer player is the white team.
		cc=4			//Run the chess program in Computer vs. Computer mode.
	
};
enum PieceColor{WHITE=-1,BLACK=1};
enum MovePieceType{MOVEFROM=1,MOVETO=2,KILL=3};
enum Moves{taken=1,empty=0,dne=-1};
enum PieceType{
	PAWN=0,
	ROOK=1,
	KNIGHT=2,
	BISHOP=3,
	KING=4,
	QUEEN=5,
};

#endif