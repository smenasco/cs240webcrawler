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
#include <iostream>
#include <cassert>
#include "UnitTest.h"
//#define DEBUG

class URLFilter{
private:
	
	std::string url;
	std::string scope;
	
	//! Sets the scope of the current filter
	//! @param origURL  the url to parse the scope from
	void SetScope(const std::string & origURL);
	
public:

	
	//  Method used for unit testing
	static bool Test(std::ostream & os);
	
	//!  Constructor.  Creates a new URLFilter with a scope.
	URLFilter(const std::string & origURL);
	
	
	//!  Destructor
	~URLFilter();
	
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
	bool IsHTML(const std::string & testurl);
	
	bool CheckSuffix(const std::string & suffix);
	
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
	bool IsInScope(const std::string & testurl);
	
	const std::string & GetScope() const;
	
};
#endif