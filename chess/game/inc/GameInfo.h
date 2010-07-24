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

enum PieceColor{WHITE=-1,BLACK=1};
enum ChessPlayer{PLAYER1=0,PLAYER2=1};
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