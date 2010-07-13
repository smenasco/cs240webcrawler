#ifndef HTMLPARSER_H
#define	HTMLPARSER_H
/*
 *  HTMLParser.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */ 

#include "HTMLTokenizer.h"

#include <string>


class HTMLParser{
private:
	
	//! Delete HTMLParser from memory
	void Free();
	
	//! Called from constructor, copy constructor, and assignment operator
	void Init(const HTMLParser & other);
	
	
public:
	
	//!  No-arg constructor.  Initializes an empty HTMLParser
	HTMLParser();
	
	
	//!  Copy constructor.  Makes a complete copy of its argument
	HTMLParser(const HTMLParser & other);
	
	
	//!  Destructor
	~HTMLParser();
	
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	HTMLParser& operator =(const HTMLParser & other);
	
};


#endif