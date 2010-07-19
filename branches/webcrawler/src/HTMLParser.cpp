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

void HTMLParser::Clean(){
	if (stream != NULL){
		delete stream;
		stream = NULL;
	}
	
	if (tokenizer != NULL) {
		delete tokenizer;
		tokenizer = NULL;
	}
}

//! Called from constructor, copy constructor, and assignment operator
void HTMLParser::Init(){
	try {
		foundDescription = false;
		description= "";
		count = 0;
		
		if (path.empty())
			return;
		stream = new URLInputStream(path);
		tokenizer = new HTMLTokenizer(stream);
		
		path = stream->GetLocation();
		
		stream->Close();
	}
	catch (std::exception &e) {
		
		std::cout << "HTMLParser: Exception Occurred:" << e.what() << std::endl;
		path = "";
		Clean();
	
	}
	catch (CS240Exception &e) {
		std::cout << "HTMLParser: Exception Occurred:" << e.GetMessage() << std::endl;
		path = "";
		Clean();
	}
	catch (...) {
		std::cout << "HTMLParser: Unknown Exception Occurred" << std::endl;
		path = "";
		Clean();
	}
}


//!  Constructor.  Initializes an empty HTMLParser
//!  @param p the path to set the HTMLParser to parse
HTMLParser::HTMLParser(WordIndex * w,
					   URLQueue * q,
					   PageIndex * i,
					   URLFilter *f): path(""),
					   words(w),urlQueue(q),pageIndex(i),filter(f),
						stream(NULL),tokenizer(NULL){
							
							pagesParsed = 0;
							Init();
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
	path = p;
	Init();
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
		//std::cout << "=======================================" << std::endl;
		//std::cout << "Actual Location: " << path << std::endl;
		//This is where the actual parsing beings
		
		pagesParsed++;
		if (CheckHTML()) {
#ifdef DEBUG
			std::cout << "This is HTML, index it\n";
#endif			
			pageIndex->Insert(path,description);

		} else {
#ifdef DEBUG
			std::cout << "This is NOT HTML, so dont index it\n";
#endif
		}
		std::cout << pagesParsed<<" Parsed URL: "<< path << std::endl;
		Clean();
		
		
	}
	catch (std::exception &e) {
		std::cout << "Exception Occurred:" << e.what() << std::endl;
		Clean();
	}
	catch (CS240Exception &e) {
		std::cout << "CS240Exception Occurred:" << e.GetMessage() << std::endl;
		Clean();
	}
	catch (...) {
		std::cout << "Unknown Exception Occurred" << std::endl;
		Clean();
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
#ifdef DEBUG
			std::cout << "Found Start HTML tag\n";
#endif
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
#ifdef DEBUG
			std::cout << "Found End HTML tag\n";
#endif
			return;
		} else if (tokenval == "title" && type == TAG_START){
#ifdef DEBUG
			std::cout << "Found Title start tag\n";
#endif
			ParseTitle();
		} else if (tokenval == "script" && type == TAG_START){
#ifdef DEBUG
			std::cout << "Found Script start tag\n";
#endif
			ParseScript();
		} else if (tokenval == "body" && type == TAG_START){
#ifdef DEBUG
			std::cout << "Found Body start tag \n";
#endif
			ParseBody();
		} else if (tokenval == "a" && type == TAG_START){
#ifdef DEBUG
			std::cout << "Found start a tag\n";
#endif
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
#ifdef DEBUG
			std::cout << "Found start a tag\n";
#endif
			ParseHREF(token);
		} else if (tokenval == "title" && type == TAG_END){
#ifdef DEBUG	
			std::cout << "Found Title end tag\n";
#endif			
			return;
		} else if (tokenval == "script" && type == TAG_START){
#ifdef DEBUG			
			std::cout << "Found Script start tag\n";
#endif
			ParseScript();
		} else if (tokenval == "body" && type == TAG_START){
#ifdef DEBUG	
			std::cout << "Found Body start tag \n";
#endif
			ParseBody();
		} else if (type == TEXT){
			SetDescription(token);
			if (!description.empty())
				foundDescription= true;
		} else if (tokenval == "html" && type == TAG_END){
#ifdef DEBUG
			std::cout << "Found End HTML tag\n";
#endif
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
#ifdef DEBUG
			std::cout << "Found start a tag\n";
#endif
			ParseHREF(token);
		} else if (tokenval == "body" && type == TAG_END){
#ifdef DEBUG			
			std::cout << "Found body end tag\n";
#endif			
			return;
		} else if (tokenval == "script" && type == TAG_START){
#ifdef DEBUG			
			std::cout << "Found Script start tag\n";
#endif
			ParseScript();
		} else if (type == TEXT){
			if (foundDescription){
				ParseText(token);
			} else
				SetDescriptionBody(token);
		} else if (tokenval == "html" && type == TAG_END){
#ifdef DEBUG
			std::cout << "Found End HTML tag\n";
#endif
			return;
		} else if (tokenval[0] == 'h' && isdigit(tokenval[1])&& foundDescription == false){
#ifdef DEBUG
			std::cout << "Found Heading: " << tokenval<< std::endl;
#endif
			
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
#ifdef DEBUG			
			std::cout << "Found start a tag\n";
#endif
			ParseHREF(token);
		} else if (tokenval == "script" && type == TAG_START){
#ifdef DEBUG			
			std::cout << "Found Script start tag\n";
#endif
			ParseScript();
		} else if (type == TEXT){
			if (!foundDescription)
				SetDescription(token);
			else 
				ParseText(token);
			foundDescription = true;
		} else if (tokenval == "html" && type == TAG_END){
#ifdef DEBUG			
			std::cout << "Found End HTML tag\n";
#endif	
			return;
		} else if (tokenval == headingName && type == TAG_END){
#ifdef DEBUG			
			std::cout << "Found Heading end : " <<headingName<< std::endl;
#endif			
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
#ifdef DEBUG
			std::cout << "Char to add: " << tokenval[i] << std::endl;
#endif
		}	
		i++;
	}
	
#ifdef DEBUG
	std::cout << "The Description ( "<< count << "): " << description << std::endl;
#endif
	ParseText(token);
	return;
}

void HTMLParser::SetDescription(const HTMLToken & t ){
	HTMLToken token = t;
	description = description + token.GetValue();
#ifdef DEBUG
	std::cout << "The Description: " + description << std::endl;
#endif
	ParseText(token);
	return;
}

void HTMLParser::ParseHREF(const HTMLToken & t ){
	HTMLToken token = t;
	if (token.AttributeExists("href")){
#ifdef DEBUG
		std::cout << "Found HREF: " << token.GetAttribute("href") << std::endl;
#endif
		
		URLFilter * f = new URLFilter(path);
		if (token.GetAttribute("href")[0] == '#'){
#ifdef DEBUG
			std::cout << "Ignoring HREF: " << token.GetAttribute("href") << std::endl;
#endif
			delete f;
			return;
		}
		
		
		URL * u = new URL(f->GetScope(),token.GetAttribute("href"));
		delete f;
#ifdef DEBUG
		std::cout << "Full URL: " << u->GetURL() << std::endl;
#endif
		if (u->GetURL() == path){
#ifdef DEBUG
			std::cout << "we've got circles!: " << u->GetURL() << std::endl;
#endif
			delete u;
			return;

		}
		if ((filter->IsHTML(u->GetURL())) && (filter->IsInScope(u->GetURL()))){
			
			if (pageIndex->Find(u->GetURL())){
#ifdef DEBUG
				std::cout << "We done already been indexin' that junx\n";
#endif
			} else {
#ifdef DEBUG
				std::cout << "Adding URL to Queue: " << u->GetURL()<< std::endl;
#endif
				urlQueue->Push(u->GetURL());				
			}
		}
		delete u;
		
		
	}
	return;
}



void HTMLParser::ParseScript(){
	while(tokenizer->HasNextToken()){
		HTMLToken token = tokenizer->GetNextToken();
		HTMLTokenType type = token.GetType();
		
		std::string tokenval = StringUtil::ToLowerCopy(token.GetValue());
		
		if (tokenval == "script" && type == TAG_END){
#ifdef DEBUG
			std::cout << "Found End Script tag\n";
#endif
			return;
		}
	}
	
}



void HTMLParser::ParseText(const HTMLToken & t ){
	HTMLToken token = t;
	
	string tokenval = 	 StringUtil::TrimCopy(token.GetValue());

	//tokenizer token.GetValue into separate words... delimit using whitespace and any 
	//non wordcharacters then filter words that dont start with alphabetic chars... all 
	//case-insensitive after words have been filtered as "words" then check them against 
	//stopwords file after they are filtered futher, add the remaining to the wordindex 
	//using path.
	
	/*htmlparse will:
	 break strings into words
	 
	 The following characters are word characters
	 
	 alphabetic	characters
	 numeric characters
	 underscore (_)
	 dash (-)
	 
	 words must start with alphabetic char
	 
	 
	 */

	if (!tokenval.empty()){
#ifdef DEBUG
		std::cout << "Found Text: " << tokenval << std::endl; 
#endif
		curPos = 0;
		while (curPos < (int)tokenval.length()){
			while(!(isalpha(tokenval[curPos]) || 
				   isdigit(tokenval[curPos]) || 
				   tokenval[curPos] == '-' || 
				   tokenval[curPos] == '_' ) 
				  && curPos < (int)tokenval.length()){
				curPos++;
			}
			std::string word = GetWord(tokenval);	
			if (!word.empty() && isalpha(word[0])){
#ifdef DEBUG
				std::cout << "Word: " << word << std::endl;
#endif
				word = StringUtil::ToLowerCopy(word);
				words->Insert(word,path);
			}
		}

		
		curPos = 0;
	}

}

const std::string HTMLParser::GetWord(std::string & phrase){
	std::string word = "";
	while (isalpha(phrase[curPos]) || 
		   isdigit(phrase[curPos]) || 
		   phrase[curPos] == '-'   || 
		   phrase[curPos] == '_' ){
		word += phrase[curPos];
		curPos++;
	}
	return word;
}