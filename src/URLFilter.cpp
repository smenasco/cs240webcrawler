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
	if (testurl[(testurl.length()-1)]=='/')
		return true;
	int pos = testurl.rfind ('/');
	std::string suffix =testurl.substr(pos+1,std::string::npos);

	return CheckSuffix(suffix);
}


bool URLFilter::CheckSuffix(const std::string & s){
	//we are going to get something that looks like "index.html"
	//so we dont really have a true suffix yet. still need to find the period.
	int pos = s.find ('.');
	if (pos == std::string::npos) //if there was no extention then its HTML
		return true;
	
	std::string suffix = s.substr(pos+1,std::string::npos);
	//std::cout << "suffix: " << suffix << std::endl;
	std::string  testcases[10];
	testcases[0] = "html";
	testcases[1] = "htm";
	testcases[2] = "shtml";
	testcases[3] = "cgi";
	testcases[4] = "jsp";
	testcases[5] = "asp";
	testcases[6] = "aspx";
	testcases[7] = "php";
	testcases[8] = "pl";
	testcases[9] = "cfm";
	for (int i = 0; i < 10;i++){
		if (suffix == testcases[i])
			return true;
	}
	return false;

	
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

bool URLFilter::Test(std::ostream & os) {
	bool success = true;
	
	//1
	URLFilter filter("http://www.cnn.com/pages/index.html"); //this sets the current scope
	//Tests IsHTML Method
	TEST( filter.IsHTML("http://www.cnn.com/"));
	TEST( filter.IsHTML("http://www.cnn.com/index.html"));
	TEST( filter.IsHTML("http://www.cnn.com/index.htm"));
	TEST( filter.IsHTML("http://www.cnn.com/index.shtml"));
	TEST( filter.IsHTML("http://www.cnn.com/index.cgi"));
	TEST( filter.IsHTML("http://www.cnn.com/index.jsp"));
	TEST( filter.IsHTML("http://www.cnn.com/index.asp"));
	TEST( filter.IsHTML("http://www.cnn.com/index.aspx"));
	TEST( filter.IsHTML("http://www.cnn.com/index.php"));
	TEST( filter.IsHTML("http://www.cnn.com/index.pl"));
	TEST( filter.IsHTML("http://www.cnn.com/index.cfm"));
	TEST(!filter.IsHTML("http://www.cnn.com/index.mp3"));
	//Tests IsInScope Method
	TEST( filter.IsInScope("http://www.cnn.com/pages/index.mp3"));
	TEST(!filter.IsInScope("file://www.cnn.com/pages/index.mp3"));
	TEST(!filter.IsInScope("http://www.cnn.com/index.mp3"));
	TEST( filter.IsInScope("http://www.cnn.com/pages/music/themesong.mp3"));
	TEST( filter.IsInScope("http://www.cnn.com/pages/music/themesong.mp3"));
	
	return success;
}