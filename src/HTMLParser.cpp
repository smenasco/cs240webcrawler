/*
 *  HTMLParser.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "HTMLParser.h"
#include "StringUtil.h"
#include <string>
#include <ctype.h>

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
		foundDescription = false;
		description= "";
		count = 0;
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
		description= "";
		count = 0;
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
		//This is where the actual parsing beings
		
		CheckHTML();
			
		
		
		
		
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


//! Stole this from HTMLToken Class because its useful and 
//! I didnt want HTMLParser to have  to be friends with HTMLToken
bool HTMLParser::IsTag(HTMLTokenType type) const {
	return type == TAG_START || type == TAG_END;
}


//! Checks see if current path is actually HTML
//! @NOTE this does not check to see if it was handed a
//! valid HTML url, the URLFilter should do that before it Queue's them
//!
//! @return TRUE if was in fact HTML, and needs to be indexed
//!			FALSE if we can just ignore it and move on
bool HTMLParser::CheckHTML(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		//std::cout << "type: "<<TypeToString(type)<< " Value: " << token.GetValue()<< std::endl;
		
		std::string tokenval = StringUtil::ToLowerCopy(token.GetValue());
	
		
		if (tokenval == "html" && type == TAG_START){
			std::cout << "Found Start HTML tag\n";
			ParseHTML();
			return true;
		}
		
			
	}
	return false;
}



//!  The following methods are different states in the Parsing state machine.
//!  They will be called by each other as the HTMLParser encounters different 
//!  States... I think its pretty awesome, you should see my drawing of the 
//!  state machine altogether in all of its glory.  It would bring you to tears.
//!
//!  There states and purpose should be pretty self explanatory.
void HTMLParser::ParseHTML(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		
		std::string tokenval;
		if (IsTag(type))
			tokenval = StringUtil::ToLowerCopy(token.GetValue());
		else 
			tokenval = token.GetValue();
		
		if (tokenval == "html" && type == TAG_END){
			std::cout << "Found End HTML tag\n";
			return;
		} else if (tokenval == "title" && type == TAG_START){
			std::cout << "Found Title start tag\n";
			ParseTitle();
		} else if (tokenval == "script" && type == TAG_START){
			std::cout << "Found Script start tag\n";
			ParseScript();
		} else if (tokenval == "body" && type == TAG_START){
			std::cout << "Found Body start tag \n";
			ParseBody();
		} else if (tokenval == "a" && type == TAG_START){
			std::cout << "Found start a tag\n";
			ParseHREF(token);
		}
	}
	//call end
	
}

void HTMLParser::ParseTitle(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		//description = "";
		std::string tokenval;
		if (IsTag(type))
			tokenval = StringUtil::ToLowerCopy(token.GetValue());
		else 
			tokenval = token.GetValue();
		
		if (tokenval == "a" && type == TAG_START){
			std::cout << "Found start a tag\n";
			ParseHREF(token);
		} else if (tokenval == "title" && type == TAG_END){
			std::cout << "Found Title end tag\n";
			return;
		} else if (tokenval == "script" && type == TAG_START){
			std::cout << "Found Script start tag\n";
			ParseScript();
		} else if (tokenval == "body" && type == TAG_START){
			std::cout << "Found Body start tag \n";
			ParseBody();
		} else if (type == TEXT){
			SetDescription(token);
			if (!description.empty())
				foundDescription= true;
		} else if (tokenval == "html" && type == TAG_END){
			std::cout << "Found End HTML tag\n";
			return;
		}	
		
	}
	//call end
}

void HTMLParser::ParseBody(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		
		std::string tokenval;
		if (IsTag(type))
			tokenval = StringUtil::ToLowerCopy(token.GetValue());
		else 
			tokenval = token.GetValue();
			
		if (tokenval == "a" && type == TAG_START){
			std::cout << "Found start a tag\n";
			ParseHREF(token);
		} else if (tokenval == "body" && type == TAG_END){
			std::cout << "Found body end tag\n";
			return;
		} else if (tokenval == "script" && type == TAG_START){
			std::cout << "Found Script start tag\n";
			ParseScript();
		} else if (type == TEXT){
			if (foundDescription){
				ParseText(token);
			} else
				SetDescriptionBody(token);
		} else if (tokenval == "html" && type == TAG_END){
			std::cout << "Found End HTML tag\n";
			return;
		} else if (tokenval[0] == 'h' && isdigit(tokenval[1])&& foundDescription == false){
			std::cout << "Found Heading: " << tokenval<< std::endl;
			description = "";
			ParseHeading(token);
		}
		
	}
}

void HTMLParser::ParseHeading(const HTMLToken & t){
	string headingName = t.GetValue();
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		
		std::string tokenval;
		if (IsTag(type))
			tokenval = StringUtil::ToLowerCopy(token.GetValue());
		else 
			tokenval = token.GetValue();
		
		if (tokenval == "a" && type == TAG_START){
			std::cout << "Found start a tag\n";
			ParseHREF(token);
		} else if (tokenval == "script" && type == TAG_START){
			std::cout << "Found Script start tag\n";
			ParseScript();
		} else if (type == TEXT){
			SetDescription(token);
			foundDescription = true;
		} else if (tokenval == "html" && type == TAG_END){
			std::cout << "Found End HTML tag\n";
			return;
		} else if (tokenval == headingName && type == TAG_END){
			std::cout << "Found Heading end : " <<headingName<< std::endl;
			return;
		}
		
	}
}

void HTMLParser::SetDescriptionBody(const HTMLToken & t ){
	//need to count to 100 the number of chars in token.GetValue and keep adding 
	//to description until we read 100 chars (exluding whitespace)
	HTMLToken token = t;
	string tokenval = token.GetValue();
	int i =0;
	
	while (count != 100 && i < (int)tokenval.length()) {
		description = description + tokenval[i];
		if (isgraph(tokenval[i])){
			//checks to see if it is a prinitable char that is not whitespace
			count++;
			std::cout << "Char to add: " << tokenval[i] << std::endl;
		}	
		i++;
	}
	
	std::cout << "The Description ( "<< count << "): " << description << std::endl;
	ParseText(token);
	return;
}

void HTMLParser::SetDescription(const HTMLToken & t ){
	HTMLToken token = t;
	description = description + token.GetValue();
	std::cout << "The Description: " + description << std::endl;
	ParseText(token);
	return;
}

void HTMLParser::ParseHREF(const HTMLToken & t ){
	HTMLToken token = t;
	if (token.AttributeExists("href")){
		std::cout << "Found HREF: " << token.GetAttribute("href") << std::endl;
		//call FilterURL to see if needs to be added  to URLQueue;
	}
	return;
}



void HTMLParser::ParseScript(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		
		std::string tokenval = StringUtil::ToLowerCopy(token.GetValue());
		
		if (tokenval == "script" && type == TAG_END){
			std::cout << "Found End Script tag\n";
			return;
		}
	}
	
}



void HTMLParser::ParseText(const HTMLToken & t ){
	HTMLToken token = t;
	
	string tokenval = 	 StringUtil::TrimCopy(token.GetValue());

	//tokenizer token.GetValue into separate words... delimit using whitespace and any non wordcharacters
	//then filter words that dont start with alphabetic chars... all case-insensitive
	//after words have been filtered as "words" then check them against stopwords file 
	//after they are filtered futher, add the remaining to the wordindex using path.
	if (!tokenval.empty()){
		std::cout << "Found Text: " << tokenval << std::endl; //this is where we would do all that checking
	}
}