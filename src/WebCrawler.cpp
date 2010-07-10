/*
 *  WebCrawler.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "WebCrawler.h"
#include "URL.h"
#include <string>

//! WebCrawler implements a webcrawler
//!  No-arg constructor.  Initializes an empty linked list
WebCrawler::WebCrawler(){
}

//!  Initizes a new webcrawler with the start URL, output file, and stopwords file 
WebCrawler::WebCrawler(const URL & url,const std::string & op,const std::string & sw) {
}

//LLNode(const std::string & v, LLNode * p, LLNode * n) : value(v), prev(p), next(n){
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
const URL & WebCrawler::GetStartURL() const {
	return startURL;
}


//!  Begin the crawling process with the given start URL, output file location, and stopwords file
void WebCrawler::Crawl(){
	return;
}


