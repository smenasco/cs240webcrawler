/*
 *  WebCrawler.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "WebCrawler.h"

#include <string>

//! WebCrawler implements a webcrawler
//!  No-arg constructor.  Initializes an empty linked list
WebCrawler::WebCrawler() : startURL(NULL), outputFileName(NULL), stopwordsFileName(NULL){
}

//! Call delete on the WebCrawler
void WebCrawler::Free() {
	
}

//! Initialize the webcrawler using a reference to other, a webcrawler
void WebCrawler::Init(const WebCrawler & other) {
	
}
//!  Copy constructor.  Makes a complete copy of its argument
WebCrawler::WebCrawler(const WebCrawler & other) {
	Init(other);
}


//!  Destructor 
WebCrawler::~WebCrawler() {
	Free();
}


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
WebCrawler & WebCrawler::operator =(const WebCrawler & other) {
	
}

//!  Return a pointer to the StartURL
std::string * WebCrawler::GetStartURL(){
	return startURL;
}


