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

#include "PageIndex.h"
#include "WordIndex.h"
#include "OccurrenceSet.h"
#include "StringUtil.h"
//!To use this method when writing XML to output
//!@return A copy of str in which each character in str which are considered
//!an XML special character (&,<,>,',") will be converted to an XML entity( & -> &amp;amp;).
//!std::string EncodeToXmlCopy (const std::string & str);

#include <string>
#include <iostream>
#include <fstream>

class XMLGenerator{
	
public:
	
	//!  Constructor.  Initializes an empty XMLGenerator using the filename from the commandline
	//!  @param outputFile where to write output to on the commandline
	//!  @param startURL the url to be printed between the <start-url> tags
	//!  @param PageIndex the index of web pages that needs to be iterated over and printed
	//!  @param wordIndex the index of words that needs to be iterated over and printed
	XMLGenerator(const std::string & o,
				 const std::string & u,
				 PageIndex * p,
				 WordIndex * w);
	
	
	//!  Destructor
	~XMLGenerator();
	
	
	
	//! The caller function to begin writing all of the XML to an outputFile
	//!
	//! @throws FileException when there is an error writing to a file
	void WriteXML();
private: 
	std::string outputFile;
	std::string startURL;
	PageIndex * pageIndex;
	WordIndex * wordIndex;
	std::ofstream output;
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
		description,
		occurrence,
		count,
		word,
		value,
	};
	
	//!  Prints a specified number of tabs to standard out;
	//!  @param n number of tabs to print
	std::string PrintTab(int n);
	
	//!  Writes a formatted xml tag of specified type to standard out
	//!  Example:
	//!  WriteStartTag(website);
	//!
	//!  Output:
	//!
	//!  <website>
	//!
	//!  @param type the XML tag to be printed 
	std::string WriteStartTag(XMLTagType type);
	
	
	//!  Writes a formatted xml tag of specified type to standard out
	//!  Example:
	//!  WriteStartTag(website);
	//!
	//!  Output:
	//!
	//!  </website>
	//!
	//!  @param type the XML tag to be printed 
	std::string WriteEndTag(XMLTagType type);
	
	
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
	void IteratePages(PageNode * n);
	
	
	//!  Iterates over the WordIndex of successfully indexed words
	//!  and prints each word parent and its children tags to standard out
	//!  calls IterateOccurrences to print Occurrences
	void IterateWords(WordNode * n);
	
	//!  Iterates over the Occurences of a particular word
	//!  and calls WriteOccurence() on each Occurrence prints each 
	//!  occurrence parent tag and its children tags to standard out
	void IterateOccurrences(OccurrenceNode * n);
	
	std::string XMLTagToString(XMLTagType type);
	
};


#endif