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



//!  Constructor with a url that needs resolved
//!
//!  @param base The value to which you base your resolved URL from
//!  @param rel the part of the URL to be resolved into the base
URL::URL(const std::string & base, const std::string & rel){
	//check if needs resolved else just set fullurl to rel;
	std::string f =  "file://";
	std::string h = "http://";
	if ( rel.substr(0,7) != f && rel.substr(0,7) != h ){
			resolveURL(base,rel);
	} else{
		if (rel[0] == '#'){
			fullurl+=rel;
		} else
		fullurl = rel;
	}
		
	StripURL();
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
const std::string & URL::GetURL() const {
	return fullurl;
}

void URL::StripURL(){
	int pos = fullurl.find('#');
	fullurl = fullurl.substr(0,pos);
}

//! Called from Constructor with two arguments
//!
//!  @param b The value to which you base your resolved URL from
//!  @param r the part of the URL to be resolved into the base
void URL::resolveURL(const std::string & b, const std::string & r){
	final = "";
	base=b;
	rel=r;
	slashCount = 0;
	cur = 0;
		
	countSlashes();
	resolveURLWorker();
	fullurl = final;
}
	
	
void URL::countSlashes(){
		slashCount=0;
		for (unsigned int i = 0; i < base.length(); i++){
			if (base[i]=='/'){
				slashes[slashCount]=i;
				slashCount++;
			}			
		}
	}
	
	
void URL::resolveURLWorker(){
		
		int numKill = 0;	//number of slashes to back up to.
		int placeholder;	//store the value rel[placeholder] where the last slash is
		if (slashCount == 2){
			base+="/";
			countSlashes();
		}
		
		//check to see if relative url begins with slash, if it does resolve it
		if (rel[0] == '/'){ 
			
			
			for (int i =0; i < slashes[2];i++) final+=base[i]; //output base url
			final+=rel;
			return;
		} 
		
		//check to see if relative url begins with lb. sign, if it does resolve it
		if (rel[0] == '#'){ 
			final+=base;
			final+=rel;
			return;
		} 
		
		//check to see if relative url doesnt begin with a dot, a slash, or a lb. sign
		if ((rel[0] != '.') && (rel[0] != '/') && (rel[0] != '#')){ 
			for (int i =0; i <=  slashes[slashCount-1];i++) final+=base[i]; //output base url
			final+=rel;
			return;
		}
		
		//loop through relative url to find double dot slashes
		for (unsigned int i=0;i+2<rel.length();i++){ 
			if (rel[i]=='.'){
				if (rel[i+1]=='/'){
					//found dot slash
					if (rel[i+2]!='.') 
						placeholder=i+1;
				}
				else if (rel[i+1]=='.'){
					//found double dot
					if (rel[i+2]=='/'){
						if (i+3<rel.length() && rel[i+3]!='.') 
							placeholder=i+2;
						//found double dot slash
						numKill+=1;
						
					}
				}
			}
		}

		int stop = slashes[slashCount-1-numKill];   //output the resolved url
		if (slashCount-numKill<3)
			stop = slashes[2];
		for (int i = 0;i < stop;i++) final+= base[i];
		for (unsigned int i = placeholder; i < rel.length();i++) final+=rel[i];
		return;
	}