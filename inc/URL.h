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
#include <string>


class URL{
private:
	//   format = <scheme>://<net_loc>/<path>?<query>#<fragment>
	std::string fullurl;
	std::string net_loc;
	std::string urlpath;
	
	
	void Free();
	void Init(const URL & other);
public:
	
	//!  No-arg constructor.  Initializes an empty URL
	URL();
	
	
	//!  Copy constructor.  Makes a complete copy of its argument
	URL(const URL & other);
	
	
	//!  Destructor
	~URL();
	
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	URL& operator =(const URL & other);
	
	const std::string & getURL() const;
	
	
	
};
#endif