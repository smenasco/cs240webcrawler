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

#include <string>
class StopWords{
	
private:
	int count;	//number of stopwords to iterate through when searching for words
	//Array [] words //dynamically allocated array of strings
	
	
public: 
	//!  No-arg constructor.  Initializes an empty StopWords
	StopWords();
	
	//!  Constructor with a url that needs resolved
	//!
	//!  @param filelocation string containing the location of the file to load
	StopWords(const std::string & filelocation);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	StopWords(const StopWords & other);
	
	
	//!  Destructor
	~StopWords();
	
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	StopWords& operator =(const StopWords & other);
	
	
	//! Load the stopwords file into dynamically sized array
	//!
	//! @param file the filename to look for in the current working directory to be loaded into array
	void Load(const std::string & file);
	
	//! Find string in Array of StopWords
	//! Implements a binary search through an array
	//! @param word the existance of the word that we are interested in
	//!
	//! @return return the stopword if it was found, else return NULL
	const std::string & Find(const std::string & word) const;
	
	
	
};


#endif 
