#ifndef WEBCRAWLER_H
#define WEBCRAWLER_H
/*
 *  WebCrawler.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */ 

#include <string>
#include "URL.h"


//!  WebCrawler implements a WebCrawler 
class WebCrawler {
public:
	
	//!  No-arg constructor.  Initializes an empty webcrawler
	WebCrawler();
	
	//!  Constructor.  Initizes a new webcrawler 
	//!  @param  url the start-URL to be indexed
	//!  @param op the name of the output-file
	//!  @param sw the name of the stopwords-file
	WebCrawler(const std::string & url,const std::string & op,const std::string & sw);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	WebCrawler(const WebCrawler & other);
	
	
	//!  Destructor
	~WebCrawler();
	
	
	//!  @return a pointer to start URL
	 std::string  GetStartURL() ;
	
	//!  Begin the crawling process with the given start URL, output file location, and stopwords file
	void Crawl();
	
private:
	std::string outputFileName;
	std::string stopwordsFileName;
	std::string startURL;
	
	void Free();
	
	void Init(const WebCrawler & other);
	
};
#endif