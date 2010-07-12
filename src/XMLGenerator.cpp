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
#include <fstream>
#include <iostream>


	
//!  No-arg constructor.  Initializes an empty XMLGenerator
XMLGenerator::XMLGenerator(){
		
	}
	

//!  Constructor.  Initializes an empty XMLGenerator using the filename from the commandline
XMLGenerator::XMLGenerator(const std::string & outputfile){
	
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

//! Tells the XMLGenerator where to write its XML
void setOutputFile(const std::string & outputfile);


//! The caller function to begin writing all of the XML to an outputfile
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
//!				<occurence>
//!					<url>www.theurl.com</url>
//!					<count>x</count>
//!				</occurence>
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
	
	/*
	 PSUEDO CODE FOR WRITING XML
	 //ofstream file(outputfile); 
	 WriteStartTag(website);
	 cout << endl;
	 cout << "\t";
	 WriteStartTag(url);
	 WriteStartURL();
	 Write
	 
	 
	 
	 
	 
	 
	 */
}

 