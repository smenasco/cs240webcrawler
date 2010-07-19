/*
 *  XMLGenerator.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */



#include "XMLGenerator.h"

//!  Constructor.  Initializes an empty XMLGenerator using the filename from the commandline
XMLGenerator::XMLGenerator(const std::string & o,
						   const std::string & u,
						   PageIndex * p,
						   WordIndex * w) : 
							outputFile(o),
							startURL(u),
							pageIndex(p),
							wordIndex(w)	{
								return;
}

	
	
//!  Destructor
XMLGenerator::~XMLGenerator(){
		
}

//! The caller function to begin writing all of the XML to an outputFile
//! An XML File will have the form:  
//!
//! <website>
//!		<start-url>www.thestarturl.com</start-url>
//!		<pages>
//!			<page>
//!				<url>theurl</url>
//!				<description>thedescription</description>
//!			</page>
//!		</pages>
//!		<index>
//!			<word>
//!				<value>thevalue</value>
//!				<Occurrence>
//!					<url>www.theurl.com</url>
//!					<count>x</count>
//!				</Occurrence>
//!			</word>
//!		</index>
//!	</website>
//!
//! The following tags are unique
//!		-website
//!		-start-url
//!		-index
//!
//! 
//!
//! @throws FileException when there is an error writing to a file
void XMLGenerator::WriteXML(){
	try {
		
		output.open(outputFile.c_str());
		output << WriteStartTag(website) << std::endl;
		output << PrintTab(1) << WriteStartTag(start_url)
		<< startURL << WriteEndTag(start_url) <<std::endl;
		
		//write <pages> and children
		output << PrintTab(1)<<WriteStartTag(pages) << std::endl;
		
		PageNode * proot = pageIndex->GetRoot(); 
		IteratePages(proot);

		output << PrintTab(1) << WriteEndTag(pages) << std::endl;
		
		
		//write <index> and children
		output << PrintTab(1) << WriteStartTag(index) << std::endl;
		
		WordNode * wroot = wordIndex->GetRoot();
		IterateWords(wroot);
		
		output << PrintTab(1) << WriteEndTag(index) << std::endl;
		output << WriteEndTag(website) << std::endl;
		
		output.close();
	}
	catch (std::exception &e) {
		std::cout << "XMLGenerator: Exception Occurred:" << e.what() << std::endl;		
	}
	catch (CS240Exception &e) {
		std::cout << "XMLGenerator: Exception Occurred:" << e.GetMessage() << std::endl;
	}
	catch (...) {
		std::cout << "XMLGenerator: Unknown Exception Occurred" << std::endl;		
	}
	//NOTE TO SELF: make sure to hand desciptions and url's to EncodeToXml so 
	//				they dont get junxed
	
	
	/*
	 PSUEDO CODE FOR WRITING XML
	 
	 cout << endl;
	 printTab(1);
		WriteStartTag(index);
	 cout << endl;
	 IterateWords():
	 printTab(1);
		WriteEndTag(index);
	 cout << endl;
	 WriteEndTag(website);
	 
	 */
	
}

//!  Iterates over the PageIndex, Index of successfully indexed pages
//!  and calls WritePage() on each page
void XMLGenerator::IteratePages(PageNode * n){
	if (n == NULL) 
		return;
	
	std::string d;
	std::string u;
	
	PageNode * left = n->GetLeft();
	PageNode * right = n->GetRight();
	
	if(left!= NULL && !left->IsVisited())
		IteratePages(left);
	if(right != NULL && !right->IsVisited())
		IteratePages(right);
	
	n->Visit();
	d = n->GetDescription();
	u = n->GetValue();
	d = StringUtil::EncodeToXmlCopy(d);
	d = StringUtil::TrimCopy(d);
	u = StringUtil::EncodeToXmlCopy(u);
	output << PrintTab(2) <<WriteStartTag(page) <<std::endl <<
	PrintTab(3) << WriteStartTag(url) << u << WriteEndTag(url) << std::endl <<
	PrintTab(3) << WriteStartTag(description) << d << WriteEndTag(description) << std::endl <<
	PrintTab(2) << WriteEndTag(page)<< std::endl;
	

}


//!  Iterates over the WordIndex of successfully indexed words
//!  and prints each word parent and its children tags to standard out
//!  calls IterateOccurrences to print Occurences
void XMLGenerator::IterateWords(WordNode * n){
	if (n == NULL) 
		return;
	
	std::string d;
	std::string w;
	
	WordNode * left = n->GetLeft();
	WordNode * right = n->GetRight();
	
	if(left!= NULL && !left->IsVisited())
		IterateWords(left);
	if(right != NULL && !right->IsVisited())
		IterateWords(right);

	n->Visit();
	w = n->GetValue();
	
	output << PrintTab(2) <<WriteStartTag(word) <<std::endl <<
	PrintTab(3) << WriteStartTag(value) << w << WriteEndTag(value) << std::endl;
	
	OccurrenceSet * s = n->GetSet();
	OccurrenceNode * o = s->GetRoot();
	IterateOccurrences(o);
	
	output << PrintTab(2) << WriteEndTag(word)<< std::endl;
	
}

//!  Iterates over the Occurences of a particular word
//!  and calls WriteOccurence() on each Occurrence prints
//!  each occurence parent tag and its children tags to standard out
void XMLGenerator::IterateOccurrences(OccurrenceNode * n){
	if (n == NULL) 
		return;
	
	std::string u;  //the url to print
	
	OccurrenceNode * left = n->GetLeft();
	OccurrenceNode * right = n->GetRight();
	
	if(left!= NULL && !left->IsVisited())
		IterateOccurrences(left);
	if(right != NULL && !right->IsVisited())
		IterateOccurrences(right);
	
	n->Visit();
	u = n->GetValue();
	u = StringUtil::EncodeToXmlCopy(u);
	int c = n->GetCount();
	
	output << PrintTab(3) <<WriteStartTag(occurrence) <<std::endl <<
	PrintTab(4) << WriteStartTag(url) << u << WriteEndTag(url) << std::endl <<
	PrintTab(4) << WriteStartTag(count) << c << WriteEndTag(count) << std::endl;
	output << PrintTab(3) << WriteEndTag(occurrence)<< std::endl;
	
}

std::string XMLGenerator::XMLTagToString(XMLTagType type){
	std::string s = "";
	switch (type){
		case website:
			s+="website";
			break;
		case start_url:
			s+="start-url";
			break;
		case pages:
			s+="pages";
			break;
		case page:
			s+="page";
			break;
		case url:
			s+="url";
			break;
		case index:
			s+="index";
			break;
		case description:
			s+="description";
			break;
		case occurrence:
			s+="occurrence";
			break;
		case count:
			s+="count";
			break;
		case word:
			s+="word";
			break;
		case value:
			s+="value";
			break;
		default:
			break;
	}
	return s;
}


//!  Prints a specified number of tabs to standard out;
//!  @param n number of tabs to print
std::string XMLGenerator::PrintTab(int n){
	std::string s = "";
	for (int i = 0; i < n;i++)
		s+="\t";
	return s;
}

//!  Writes a formatted xml tag of specified type to standard out
//!  Example:
//!  WriteStartTag(website);
//!
//!  Output:
//!
//!  <website>
//!
//!  @param type the XML tag to be printed 
std::string XMLGenerator::WriteStartTag(XMLTagType type){
	std::string s = "<";
	s+=XMLTagToString(type);
	s+=">";
	return s;
}


//!  Writes a formatted xml tag of specified type to standard out
//!  Example:
//!  WriteStartTag(website);
//!
//!  Output:
//!
//!  </website>
//!
//!  @param type the XML tag to be printed 
std::string XMLGenerator::WriteEndTag(XMLTagType type){
	std::string s = "</";
	s+=XMLTagToString(type);
	s+=">";
	return s;
}

