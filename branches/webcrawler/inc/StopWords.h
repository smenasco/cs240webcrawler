#ifndef STOPWORDS_H
#define STOPWORDS_H
/*
 *  StopWords.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */ 
#include "CS240Exception.h"
#include "UnitTest.h"
#include <iostream>
#include <fstream>
#include <string>

class StopWords{
public: 
	//  Method used for unit testing
	static bool Test(std::ostream & os);
	
	
	//!  Constructor with a url that needs resolved
	//!
	//!  @param filelocation string containing the location of the file to load
	StopWords(const std::string & filelocation);
	
	
	//!  Destructor
	~StopWords();
	
	//! Load the stopwords file into dynamically sized array
	//!
	//! @param file the filename to look for in the current working directory to be loaded into array
	void Load(const std::string & filelocation);
	
	//! Find string in Array of StopWords
	//! Implements a binary search through an array
	//! @param word the existance of the word that we are interested in
	//!
	//! @return return TRUE if word was found, else return FALSE
	bool IsStopWord(const std::string & word);
	
private:
	int count;	//number of stopwords to iterate through when searching for words
	int MAX;	//the max number of words before we need to grow the array
	std::string * words;  // an array of words on the heap
	
	//Array [] words //dynamically allocated array of strings
	void AddWord(const std::string & word);	
	
};


#endif 
