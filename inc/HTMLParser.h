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
#include <iostream>
#include <string>

#include "HTMLTokenizer.h"
#include "InputStream.h"
#include "URLInputStream.h"
#include "CS240Exception.h"




class HTMLParser{

	
	
public:
	
	//!  No-arg constructor.  Initializes an empty HTMLParser
	HTMLParser();
	
	//!  Constructor.  Initializes an empty HTMLParser
	//!  @param p the path to set the HTMLParser to parse
	HTMLParser(const std::string & p);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	HTMLParser(const HTMLParser & other);
	
	
	//!  Destructor
	~HTMLParser();
	
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	HTMLParser& operator =(const HTMLParser & other);
	
	//! Begin Parsing the given HTML file
	//!
	//! @returns TRUE if URL needs indexed into WordIndex, 
	//!			 FALSE if it didnt end as HTML after all
	bool Parse();
	
	//! Resets the HTMLParser with a new path to parse
	//! @param p the path to set the HTMLParser to parse
	void SetPath(const std::string & p);
	
private:
	string path;				//!< the url to be parsed
	URLInputStream * stream;	//!< the stream to load the url from
	HTMLTokenizer *tokenizer;	//!< the downloaded page to tokenize
	bool foundDescription;		//!< keep track of whether or not the URL has found a description
	
	void Free();		//! Delete HTMLParser from memory
	
	
	//! Called from constructor, copy constructor, and assignment operator
	void Init(const HTMLParser & other);
	
};


#endif