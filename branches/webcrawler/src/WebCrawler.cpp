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
#include "URLQueue.h"
#include "XMLGenerator.h"
#include "PageIndex.h"
#include "StopWords.h"
#include "URLFilter.h"
#include "WordIndex.h"
#include "HTMLParser.h"
#include <string>

//! WebCrawler implements a webcrawler
//!  No-arg constructor.  Initializes an empty linked list
WebCrawler::WebCrawler(){
}

//!  Initizes a new webcrawler with the start URL, output file, and stopwords file 
WebCrawler::WebCrawler(const std::string & url,
					   const std::string & op,
					   const std::string & sw): 
						outputFileName(op),
						stopwordsFileName(sw),
						startURL(url) {
	return;
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



//!  Return a pointer to the StartURL
std::string WebCrawler::GetStartURL() {
	return startURL;
}


//!  Begin the crawling process with the given start URL, output file location, and stopwords file
void WebCrawler::Crawl(){
	URLQueue * urlQueue = new URLQueue(startURL);
	StopWords * stopWords = new StopWords(stopwordsFileName);
	WordIndex * words = new WordIndex(stopWords);
	PageIndex * pageIndex = new PageIndex();
	HTMLParser * parser = new HTMLParser();
	
	std::string curURL;
	try {
		
		
		while (!urlQueue->IsEmpty()){
			curURL = urlQueue->Pop();
			
			//!  This is very bare because most of the functionality we are abstacted from at this point
			//!  in the code... most of the work happens in the HTMLParser as it finds links, words, and 
			//!  descriptions
			//!
			//!  HTMLParser will ask the URLInputStream to download the URL it is pointed to and then
			//!     will populate the URLQueue with more URLs as it finds them, 
			//!		after it checks them against a URLFIlter, and resolves relative links
			//!	 Before a link is sent to the URLQueue, it is checked to see if has already been 
			//!		indexed and exists in the PageIndex.  If so it is not added to the URLQueue.
			//!  @NOTE The URLQueue only allows unique entries. so as not to get stuck in a loop.
			//!  The HTMLParser will also find words and send them to WordIndex, which will check 
			//!		against stopwords, and populate the WordIndex
			//!  HTMLParser will also populate the PageIndex with valid, parsed HTML pages & descriptions
			//!  once it determines they are, in fact, html (ie contain <html> tags)
			parser->SetPath(curURL/*,words,urlQueue,pageIndex*/); //<--- as you can see this is not fully
																  //     implemented but it will be :-)
			
			//!  As words are added to the WordIndex, word index checks to see whether or not the word
			//!		is new.  If it is new it creates a new WordNode.  It then creates a new OccurenceSet 
			//!     and the respective Occurence which the HTMLparser is parsing currently.
		}
		
		
		//There are no more links.  Lets build the output.
		XMLGenerator * output = new XMLGenerator(outputFileName,
												 startURL,
												 pageIndex,
												 words);
		output->WriteXML();
		
		
		//clean things up
		delete urlQueue;
		delete stopWords;
		delete words;
		delete pageIndex;
		delete parser;
		delete output;
		
	}
	catch (...) {
		//there would, of course, be more useful catch's here
	}
}


