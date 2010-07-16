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
#include "WordIndex.h"
#include "URLQueue.h"
#include "PageIndex.h"
#include "URLFilter.h"
#include "URL.h"

//#define DEBUG


class HTMLParser{

	
	
public:
	

	//!  Constructor.  Initializes an empty HTMLParser
	//!  @params the projects word index, url queue, pageindex, and url filter 
	//			 which all are initialized in WebCrawler->Crawl()
	//			 filter caries
	HTMLParser(WordIndex * w,
			   URLQueue * q,
			   PageIndex * i,
			   URLFilter *f);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	HTMLParser(const HTMLParser & other);
	
	
	//!  Destructor
	~HTMLParser();
	
	
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
	string description;			//!< the description of the current url being parsed.
	WordIndex * words;
	URLQueue *urlQueue;
	PageIndex * pageIndex;		
	URLFilter * filter;			//!< carries  the scope and checks if url isHTML()
	URLInputStream * stream;	//!< the stream to load the url from
	HTMLTokenizer *tokenizer;	//!< the downloaded page to tokenize
	int pagesParsed;
	int count;					//!< the number of chars in the description to be referenced 
								//!  only when adding char characters from body to desciption
	bool foundDescription;		//!< keep track of whether or not the URL has found a description
	
	void Free();		//! Delete HTMLParser from memory
	
	bool IsTag(HTMLTokenType type) const;
	
	//! Checks see if current path is actually HTML
	//! @NOTE this does not check to see if it was handed a
	//! valid HTML url, the URLFilter should do that before it Queue's them
	//!
	//! @return TRUE if was in fact HTML, and needs to be indexed
	//!			FALSE if we can just ignore it and move on
	bool CheckHTML();
	
	//!  The following methods are different states in the Parsing state machine.
	//!  They will be called by each other as the HTMLParser encounters different 
	//!  States... I think its pretty awesome, you should see my drawing of the 
	//!  state machine altogether in all of its glory.  It would bring you to tears.
	//!
	//!  There states and purpose should be pretty self explanatory.
	void ParseHTML();
	void ParseTitle();
	void ParseScript();
	void ParseBody();

	void ParseHeading(const HTMLToken & t);
	void ParseText(const HTMLToken & t);
	void ParseHREF(const HTMLToken & t);
	void SetDescription(const HTMLToken & t);
	void SetDescriptionBody(const HTMLToken & t);
	
	//! Called from constructor, copy constructor, and assignment operator
	void Init();
	
};


#endif