/*
 *  URL.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "URL.h"
#include <string>

//! Delete URL from memory
void URL::Free(){
		
}

//! Initialize a new URL
void URL::Init(const URL & other){
	
}

//!  No-arg constructor.  Initializes an empty URL
URL::URL(){
	
}

//!  Constructor.  Initializes an a URL with full URL v
URL::URL(const std::string & v): fullurl(v){
	
}

//!  Constructor with a url that needs resolved
//!
//!  @param base The value to which you base your resolved URL from
//!  @param rel the part of the URL to be resolved into the base
URL::URL(const std::string & base, const std::string & rel){
	resolveURL(base,rel);
}

//!  Copy constructor.  Makes a complete copy of its argument
URL::URL(const URL & other){
	
}


//!  Destructor
URL::~URL(){
	Free();
}


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
URL& URL::operator =(const URL & other){
	
}

//! Return full resolved URL
const std::string & URL::getURL() const {
	return fullurl;
}

//! Called from Constructor with two arguments
//!
//!  @param base The value to which you base your resolved URL from
//!  @param rel the part of the URL to be resolved into the base
void URL::resolveURL(const std::string & base, const std::string & rel){
	
}
