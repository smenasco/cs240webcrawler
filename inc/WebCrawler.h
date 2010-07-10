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


//!  WebCrawler implements a WebCrawler 
class WebCrawler {
private:
	std::string * startURL;
	std::string * outputFileName;
	std::string * stopwordsFileName;
	
	void Free();
	void Init(const WebCrawler & other);
public:
	
	//!  No-arg constructor.  Initializes an empty webcrawler
	WebCrawler();
	
	
	//!  Copy constructor.  Makes a complete copy of its argument
	WebCrawler(const WebCrawler & other);
	
	
	//!  Destructor
	~WebCrawler();
	
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	WebCrawler& operator =(const WebCrawler & other);
	
	
	//!  @return a pointer to start URL
	std::string * GetStartURL();
	
};
#endif