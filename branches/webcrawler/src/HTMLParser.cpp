/*
 *  HTMLParser.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "HTMLParser.h"
#include <string>

//! Delete HTMLParser from memory
void HTMLParser::Free(){
	
}

//! Called from constructor, copy constructor, and assignment operator
void HTMLParser::Init(const HTMLParser & other){
	
}




//!  No-arg constructor.  Initializes an empty HTMLParser
HTMLParser::HTMLParser(){
	
}

//!  Constructor.  Initializes an empty HTMLParser
//!  @param p the path to set the HTMLParser to parse
HTMLParser::HTMLParser(const std::string & p): path(p){

	try {
		stream = new URLInputStream(path);
		tokenizer = new HTMLTokenizer(stream);
		
		path = stream->GetLocation();
		
		stream->Close();
	}
	catch (std::exception &e) {
		
		std::cout << "HTMLParser: Exception Occurred:" << e.what() << std::endl;
	}
	catch (CS240Exception &e) {
			std::cout << "HTMLParser: Exception Occurred:" << e.GetMessage() << std::endl;
	}
	catch (...) {
		std::cout << "HTMLParser: Unknown Exception Occurred" << std::endl;
	}
}

//!  Copy constructor.  Makes a complete copy of its argument
HTMLParser::HTMLParser(const HTMLParser & other){
	
}


//!  Destructor
HTMLParser::~HTMLParser(){
	
}



//! Resets the HTMLParser with a new path to parse
//! @param p the path to set the HTMLParser to parse
void HTMLParser::SetPath(const std::string & p){
	try {
		path = p;
		foundDescription = false;
		delete stream;
		delete tokenizer;
		stream = new URLInputStream(path);
		tokenizer = new HTMLTokenizer(stream);
		
		path = stream->GetLocation();
		
		stream->Close();
	}
	catch (std::exception &e) {
		
		std::cout << "HTMLParser: Exception Occurred:" << e.what() << std::endl;
		path = "";
	}
	catch (CS240Exception &e) {
		std::cout << "HTMLParser: Exception Occurred:" << e.GetMessage() << std::endl;
		path = "";
	}
	catch (...) {
		std::cout << "HTMLParser: Unknown Exception Occurred" << std::endl;
		path = "";
	}	

}


//! Begin Parsing the given HTML file
//!
//! @returns TRUE if URL needs indexed into WordIndex 
//!			 FALSE if it didnt end up as HTML after all
bool HTMLParser::Parse(){
	
	try{
		if (path.empty())
			throw CS240Exception("There is no URL loaded into the HTMLParser");
		
		
		
		
		
		//Handle redirections (Find out where we redirected to)
		path = stream->GetLocation();
		std::cout << "=======================================" << std::endl;
		std::cout << "Actual Location: " << path << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception Occurred:" << e.what() << std::endl;
	}
	catch (CS240Exception &e) {
		std::cout << "CS240Exception Occurred:" << e.GetMessage() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown Exception Occurred" << std::endl;
	}
	

	
	return true;
}
