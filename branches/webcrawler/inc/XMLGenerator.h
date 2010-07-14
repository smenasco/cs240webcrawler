#ifndef XMLGENERATOR_H
#define XMLGENERATOR_H
/*
 *  XMLGenerator.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */ 

#include <string>
#include "URL.h"
#include "PageIndex.h"
#include "WordIndex.h"

class XMLGenerator{
private: 
	std::string outputFile;
	URL * startURL;
	PageIndex * pageIndex;
	WordIndex * wordIndex;
	//The following are methods called from WriteXML() 
	//They are private and as such are not known to the users.  So there.
	
	//! An XML File will have the form:  
	//!
	//! <website>
	//!		<start-url>www.thestarturl.com</start-url>
	//!		<pages>
	//!			<page>
	//!				<url>theurl</url>
	//!				<description>thedescription<>
	//!			</page>
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
	
	enum XMLTagType {
		website,
		start_url,
		pages,
		page,
		url,
		index,
		dessciption,
		occurrence,
		count,
		word,
		value,
	};
	
	//!  Prints a specified number of tabs to standard out;
	//!  @param n number of tabs to print
	void PrintTab(int n);
	
	//!  Writes a formatted xml tag of specified type to standard out
	//!  Example:
	//!  WriteStartTag(website);
	//!
	//!  Output:
	//!
	//!  <website>
	//!
	//!  @param type the XML tag to be printed 
	void WriteStartTag(XMLTagType type);
	
	
	//!  Writes a formatted xml tag of specified type to standard out
	//!  Example:
	//!  WriteStartTag(website);
	//!
	//!  Output:
	//!
	//!  </website>
	//!
	//!  @param type the XML tag to be printed 
	void WriteEndTag(XMLTagType type);
	
	
	//!  Prints each page parent and its children tags to standard out
	//!  @param n the Node to be printed
	void WritePage(PageNode * n);
	
	//!  Prints each occurrence parent tag and its children tags to standard out
	//!  @param n the Node to be printed
	void WriteOccurrence(OccurrenceNode * n);
	
	//!  Prints each word occurrence parent tag and the <value> child tag
	//!  @param n the Node to be printed
	void WriteWord(WordNode * n);
	
	//!  Iterates over the PageIndex, Index of successfully indexed pages
	//!  and calls WritePage() on each page
	void IteratePages();
	
	
	//!  Iterates over the WordIndex of successfully indexed words
	//!  and prints each word parent and its children tags to standard out
	//!  calls IterateOccurrences to print Occurrences
	void IterateWords();
	
	//!  Iterates over the Occurences of a particular word
	//!  and calls WriteOccurence() on each Occurrence prints each 
	//!  occurrence parent tag and its children tags to standard out
	void IterateOccurrences();
	
public:
	
	//!  Constructor.  Initializes an empty XMLGenerator using the filename from the commandline
	//!  @param outputFile where to write output to on the commandline
	//!  @param startURL the url to be printed between the <start-url> tags
	//!  @param PageIndex the index of web pages that needs to be iterated over and printed
	//!  @param wordIndex the index of words that needs to be iterated over and printed
	XMLGenerator(const std::string & outputFile,
				 const std::string & startURL,
				 PageIndex * pageIndex,
				 WordIndex * wordIndex);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	XMLGenerator(const XMLGenerator & other);
	
	
	//!  Destructor
	~XMLGenerator();
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	XMLGenerator& operator =(const XMLGenerator & other);
	
	
	//! The caller function to begin writing all of the XML to an outputFile
	//!
	//! @throws FileException when there is an error writing to a file
	void WriteXML();
};


#endif