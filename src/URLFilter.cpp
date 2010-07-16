/*
 *  URLFilter.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "URLFilter.h"

#include <string>


//! Delete URLFilter from memory
void URLFilter::Free(){
	
}

//! Called from constructor, copy constructor, and assignment operator
void URLFilter::Init(const URLFilter & other){
	
}






//!  Constructor.  Creates a new URLFilter with a scope.
URLFilter::URLFilter(const std::string & origURL){
	SetScope(origURL);
}

//! Sets the scope of the current filter
//! @param origURL  the url to parse the scope from
void URLFilter::SetScope(const std::string & origURL){
	assert(!origURL.empty());
	scope = "";
	int pos = origURL.rfind ('/');
	scope += origURL.substr(0,pos+1);
#ifdef DEBUG
	std::cout << "Scope  : " << scope << "\norigURL: " << origURL << std::endl;
#endif
}

//!  Copy constructor.  Makes a complete copy of its argument
URLFilter::URLFilter(const URLFilter & other){
	
}


//!  Destructor
URLFilter::~URLFilter(){
	
}


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
URLFilter& URLFilter::operator =(const URLFilter & other){
	
}

//! Checks to see if the URL is one of the following:
//!1. The <path> part of the URL is a directory name 
//!		(i.e., it ends with "/").
//!		For example, http://www.espn.com/football/
//!2. The file name in the URL's <path> does not end with a file extension 
//!		(i.e., the file name contains no periods). 
//!		For example,http://www.espn.com/football/scores
//!3. The file name in the URL's <path> ends with one of the following extensions:
//!		.html, .htm, .shtml, .cgi, .jsp, .asp, .aspx, .php, .pl, .cfm.
//!     For example, http://www.espn.com/football/scores/index.html
//! 
//! @return TRUE if holds else return FALSE
bool URLFilter::IsHTML(const std::string & testurl){
	return true;
}

//! Checks if the URL it is handed is in scope
//! Ignore any links on pages that move outside the prefix of the scope. 
//!	The prefix of the scope is everything in the URL before the page name. 
//!	For example, if the startURL is:
//!	
//!	http://cs-online.cs.byu.edu/cs240/default.htm
//!	then the prefix of the startURL is
//!	
//!	http://cs-online.cs.byu.edu/cs240/
//!
//!	If the first characters of a link's address do not exactly match the prefix of the startURL , 
//! then the link should not be processed.
//! -------------------------------------------
//! @param testURL the url that it will check
//!
//! @return TRUE if testURL is in scope else @return FALSEbool URLFilter::IsInScope(URL * testurl){
bool URLFilter::IsInScope(const std::string & testurl){
	assert(scope.length()> 0);
	//std::cout << "Scope length: " << scope.length()<< std::endl;
	for (unsigned int i = 0; i < scope.length(); i++ ){
		//std::cout << "scope["<<i<<"]: "<< scope[i] << std::endl;
		//std::cout << "testurl["<< i << "]: " << testurl[i] << std::endl;
		if (scope[i] != testurl[i])
			return false;
	}
	return true;
}


const std::string & URLFilter::GetScope() const {
	return scope;
}