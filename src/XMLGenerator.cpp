/*
 *  XMLGenerator.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */



#include "XMLGenerator.h"

#include "StringUtil.h"
//!To use this method when writing XML to output
//!@return A copy of str in which each character in str which are considered
//!an XML special character (&,<,>,',") will be converted to an XML entity( & -> &amp;amp;).
//!std::string EncodeToXmlCopy (const std::string & str);

#include <string>




//!  Constructor.  Initializes an empty XMLGenerator using the filename from the commandline
XMLGenerator::XMLGenerator(const std::string & outputFile,
						   const std::string & startURL,
						   PageIndex * pageIndex,
						   WordIndex * wordIndex) {
	
	
}

//!  Copy constructor.  Makes a complete copy of its argument
XMLGenerator::XMLGenerator(const XMLGenerator & other){
		
	}
	
	
//!  Destructor
XMLGenerator::~XMLGenerator(){
		
}
	

//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
XMLGenerator& XMLGenerator::operator =(const XMLGenerator & other){
	
}

//! The caller function to begin writing all of the XML to an outputFile
//! An XML File will have the form:  
//!
//! <website>
//!		<start-url>www.thestarturl.com</start-url>
//!		<pages>
//!			<page>
//!				<url>theurl</url>
//!				<description>thedescription<>
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
	//NOTE TO SELF: make sure to hand desciptions and url's to EncodeToXml so 
	//				they dont get junxed
	
	
	/*
	 PSUEDO CODE FOR WRITING XML
	 //ofstream file(outputFile); 
	 WriteStartTag(website);
	 cout << endl;
	 printTab(1);	
		WriteStartTag(start_url);
		WriteStartURL();
		WriteEndTag(start_url);
	 cout << endl;
	 printTab(1);
		WriteStartTag(pages);
	 cout << endl;
	 IteratePages();
	 printTab(1);
		WriteEndTag(pages);
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
//!  Prints a specified number of tabs to standard out;
//!  @param n number of tabs to print
void XMLGenerator::PrintTab(int n){
		
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
void XMLGenerator::WriteStartTag(XMLTagType type){
	
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
void XMLGenerator::WriteEndTag(XMLTagType type){
	
}


//!  Prints each page parent and its children tags to standard out
//!  @param n the Node to be printed
void WritePage(PageNode * n){
	
}

//!  Prints each occurrence parent tag and its children tags to standard out
//!  @param n the Node to be printed
void WriteOccurrence(OccurrenceNode * n){
	
}

//!  Prints each word occurrence parent tag and the <value> child tag
//!  @param n the Node to be printed
void WriteWord(WordNode * n){
	
}
	

//!  Iterates over the PageIndex, Index of successfully indexed pages
//!  and calls WritePage() on each page
void XMLGenerator::IteratePages(){
	
}


//!  Iterates over the WordIndex of successfully indexed words
//!  and prints each word parent and its children tags to standard out
//!  calls IterateOccurrences to print Occurences
void XMLGenerator::IterateWords(){
	
}

//!  Iterates over the Occurences of a particular word
//!  and calls WriteOccurence() on each Occurrence prints each occurence parent tag and its children tags to standard out
void XMLGenerator::IterateOccurrences(){
	
}


