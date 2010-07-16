/*
 *  URL.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */



#include "URL.h"



//! Delete URL from memory
void URL::Free(){
		
}

//! Initialize a new URL
void URL::Init(const std::string & base, const std::string & rel){
	//check if needs resolved else just set fullurl to rel;
	std::string f =  "file://";
	std::string h = "http://";
	if ( rel.substr(0,7) != f && rel.substr(0,7) != h ){
		resolveURL(base,rel);
	} else{
		fullurl = rel;
	}
}



//!  Constructor with a url that needs resolved
//!
//!  @param base The value to which you base your resolved URL from
//!  @param rel the part of the URL to be resolved into the base
URL::URL(const std::string & base, const std::string & rel){
	Init(base,rel);
		
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

//! Strips the uselessness of some links we may receive
void URL::StripURL(){
	int pos = fullurl.find('?');
	fullurl = fullurl.substr(0,pos);
	pos =  fullurl.find('#');
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
	ResolveDotSlash();
	
}

void URL::ResolveDotSlash(){
	//loop through relative url to find double dot slashes
	
	int numKill = 0;	//number of slashes to back up to.
	int placeholder;	//store the value rel[placeholder] where the last slash is
	
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
	PrintFinalURL(numKill,placeholder);
	
}

void URL::PrintFinalURL(int numKill,int placeholder){
	int stop = slashes[slashCount-1-numKill];   //output the resolved url
	if (slashCount-numKill<3)
		stop = slashes[2];
	for (int i = 0;i < stop;i++) final+= base[i];
	for (unsigned int i = placeholder; i < rel.length();i++) final+=rel[i];
	return;
}

//insert Test Here

bool URL::Test(std::ostream & os) {
	bool success = true;
	
	//1
	URL url("http://www.cnn.com/news/financial/index.html","/images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/images/nasdaq.jpg");
	//2
	url.Init("file:///news/financial/index.html","/images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///images/nasdaq.jpg");
	//3
	url.Init("http://www.cnn.com/news/financial/index.html","./images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/news/financial/images/nasdaq.jpg");
	//4
	url.Init("file:///news/financial/index.html","./images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///news/financial/images/nasdaq.jpg");
	//5 
	url.Init("http://www.cnn.com/news/financial/index.html","../images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/news/images/nasdaq.jpg");
	//6
	url.Init("file:///news/financial/index.html","../images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///news/images/nasdaq.jpg");
	//7
	url.Init("http://www.cnn.com","/images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/images/nasdaq.jpg");
	//8
	url.Init("file://","/images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///images/nasdaq.jpg");
	//9
	url.Init("http://www.cnn.com","images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/images/nasdaq.jpg");
	//10
	url.Init("file://","images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///images/nasdaq.jpg");
	//11
	url.Init("http://www.cnn.com","./images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/images/nasdaq.jpg");
	//12
	url.Init("file://","./images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///images/nasdaq.jpg");
	//13
	url.Init("http://www.cnn.com/news/financial/index.html","#HEADLINES"); 
	TEST(url.GetURL() == "http://www.cnn.com/news/financial/index.html#HEADLINES");
	//14
	url.Init("file:///news/financial/index.html","#HEADLINES"); 
	TEST(url.GetURL() == "file:///news/financial/index.html#HEADLINES");
	//15
	url.Init("http://www.cnn.com/news/financial/index.html","images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/news/financial/images/nasdaq.jpg");
	//16
	url.Init("file:///news/financial/index.html","images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///news/financial/images/nasdaq.jpg");
	//17
	url.Init("http://www.cnn.com/news/financial/folder/another/again/still/index.html","./../.././././.././././.././../images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/news/images/nasdaq.jpg");
	//18
	url.Init("file:///news/financial/folder/another/again/still/index.html","./../.././././.././././.././../images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///news/images/nasdaq.jpg");
	//19
	url.Init("http://www.test.com/queries?name=test","./go/here"); 
	TEST(url.GetURL() == "http://www.test.com/go/here");
	//20
	url.Init("file:///queries?name=test","./go/here"); 
	TEST(url.GetURL() == "file:///go/here");
	//21
	url.Init("http://www.test.com/queries?name=test","#stay"); 
	TEST(url.GetURL() == "http://www.test.com/queries?name=test#stay");
	//22
	url.Init( "file:///queries?name=test","#stay"); 
	TEST(url.GetURL() == "file:///queries?name=test#stay");
	//23
	url.Init( "http://www.test.com/queries?name=test","./queries?name=newquery"); 
	TEST(url.GetURL() == "http://www.test.com/queries?name=newquery");
	//24
	url.Init( "file:///queries?name=test","./queries?name=newquery"); 
	TEST(url.GetURL() == "file:///queries?name=newquery");
	//25
	url.Init( "http://www.cnn.com/news;lang=english/financial;lang=english/index.html;lang=english","./images/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/news;lang=english/financial;lang=english/images/nasdaq.jpg");
	//26
	url.Init( "file:///news;lang=english/financial;lang=english/index.html;lang=english","./images/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///news;lang=english/financial;lang=english/images/nasdaq.jpg");
	//27
	url.Init( "http://www.cnn.com/news;lang=english/financial;lang=english/index.html;lang=english","./images;lang=english/nasdaq.jpg"); 
	TEST(url.GetURL() == "http://www.cnn.com/news;lang=english/financial;lang=english/images;lang=english/nasdaq.jpg");
	//28
	url.Init( "file:///news;lang=english/financial;lang=english/index.html;lang=english","./images;lang=english/nasdaq.jpg"); 
	TEST(url.GetURL() == "file:///news;lang=english/financial;lang=english/images;lang=english/nasdaq.jpg");
	
	return success;
}