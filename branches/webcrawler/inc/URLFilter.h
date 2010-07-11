#ifndef URLFILTER_H
#define URLFILTER_H
/*
 *  URLFilter.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include <string>
#include "URL.h"

class URLFilter{
private:
	
	URL * url;
	URL * scope;
	
	//! Delete URLFilter from memory
	void Free();
	
	//! Called from constructor, copy constructor, and assignment operator
	void Init(const URLFilter & other);
	
	
public:
	
	//!  No-arg constructor.  Initializes an empty URLFilter
	URLFilter();
	
	
	//!  Constructor.  Creates a new URLFilter with a scope.
	URLFilter(const std::string & scope);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	URLFilter(const URLFilter & other);
	
	
	//!  Destructor
	~URLFilter();
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	URLFilter& operator =(const URLFilter & other);
	
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
	bool IsHTML();
	
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
	//! @return TRUE if testURL is in scope else @return FALSE
	bool IsInScope(URL * testurl);
	
};
#endif