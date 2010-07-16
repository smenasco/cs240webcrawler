#ifndef URL_H
#define URL_H
/*
 *  URL.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
#include "UnitTest.h"
#include <string>
#include <iostream>



class URL{

	
public:
	
	//  Method used for unit testing
	static bool Test(std::ostream & os);
	
	//!  Constructor with a url that needs resolved
	//!
	//!  @param base The value to which you base your resolved URL from
	//!  @param rel the part of the URL to be resolved into the base
	URL(const std::string & base, const std::string & rel);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	URL(const URL & other);
	
	
	//!  Destructor
	~URL();
	
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	URL& operator =(const URL & other);
	
	//! Return string containing full url
	const std::string & GetURL() const;
	
	//! Called from Constructor with two arguments
	//!
	//!  @param base The value to which you base your resolved URL from
	//!  @param rel the part of the URL to be resolved into the base
	void resolveURL(const std::string & base, const std::string & rel);
	
	
	
private:
	//   format = <scheme>://<net_loc>/<path>?<query>#<fragment>
	std::string fullurl;
	std::string scheme;
	std::string net_loc;
	std::string urlpath;
	
	std::string base;
	std::string rel;
	std::string final;
	int slashCount;
	int slashes[100];
	int cur;
	
	//! Delete URL from memory
	void Free();
	void ResolveDotSlash();
	void PrintFinalURL(int numKill,int placeholder);
	
	
	//! Initializes a new URL and resolves it if needed
	//! Does not strip the # or ?
	void Init(const std::string & base, const std::string & rel);
	
	void StripURL();
	
	void resolveURLWorker();
	
	void countSlashes();
};
#endif