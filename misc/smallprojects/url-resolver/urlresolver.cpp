/*
 *  urlresolver.cpp
 *  
 *
 *  Created by Sam on 6/16/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include "urlresolver.h"
#include <iostream>
#include <string>
#include <cassert>


std::string base;
std::string rel;
std::string final;
int slashCount=0;
int slashes[STRSIZE];
int cur = 0;


int main(int argc, char * argv[]) {
	base = "";
	rel = "";
	final = "";
	assert(argc == 3);
	if (argc != 3) { //check the number of args from the command line
		std::cout << "USAGE: url-resolver <base url> <relative url>\n";
		return -1;
	}	
	
	//get the base url and relative url from the command line
	base+=argv[1];
	rel+=argv[2];
	
#ifdef DEBUG
	std::cout << "base url: " << base << "\n";
	std::cout << "relative url: " << rel << "\n";
#endif
	
	
	countSlashes();
	resolveURL();
	
	return 0;
}


void countSlashes(){
	slashCount=0;
	for (int i = 0; i < base.length(); i++){
		if (base[i]=='/'){
			slashes[slashCount]=i;
			slashCount++;
			
#ifdef DEBUG
			for (int o = 0; o < i; o++) std::cout << base[o];
			std::cout << "\n";
			for (int o = 0; o < slashCount;o++) std::cout << "Slash("<<o<<"): "<< slashes[o] <<"\n";
#endif
		}
		
		
	}
}


void resolveURL(){
	
	int numKill = 0;	//number of slashes to back up to.
	int placeholder;	//store the value rel[placeholder] where the last slash is
	if (slashCount == 2){
		base+="/";
		countSlashes();
	}
	
	//check to see if relative url begins with slash, if it does resolve it
	if (rel[0] == '/'){ 
		
		assert(slashCount>=3);  //the base gots to have 3 slashes!
		for (int i =0; i < slashes[2];i++) final+=base[i]; //output base url
		final+=rel;
		return;
	} 
	
    //check to see if relative url begins with lb. sign, if it does resolve it
	if (rel[0] == '#'){ 
		final+=base;
		final+=rel;
		return;
	} 
	
	//check to see if relative url doesnt begin with a dot, a slash, or a lb. sign
	if ((rel[0] != '.') && (rel[0] != '/') && (rel[0] != '#')){ 
		for (int i =0; i <=  slashes[slashCount-1];i++) final+=base[i]; //output base url
		final+=rel;
		return;
	}
	
	//loop through relative url to find double dot slashes
	for (int i=0;i+2<rel.length();i++){ 
		if (rel[i]=='.'){
			if (rel[i+1]=='/'){
				//found dot slash
				if (rel[i+2]!='.') 
					placeholder=i+1;
			}
			else if (rel[i+1]=='.'){
				//found double dot
				if (rel[i+2]=='/'){
					if (i+3<rel.length() && rel[i+3]!='.') 
						placeholder=i+2;
					//found double dot slash
					numKill+=1;
					
				}
			}
		}
	}
#ifdef DEBUG
	std::cout<< "numKill: " << numKill << "\n";
	std::cout<< "placeholder: " << placeholder << "\n";
#endif	
	int stop = slashes[slashCount-1-numKill];   //output the resolved url
	if (slashCount-numKill<3)
		stop = slashes[2];
	for (int i = 0;i < stop;i++) final+= base[i];
	for (int i = placeholder; i < rel.length();i++) final+=rel[i];
	return;
}