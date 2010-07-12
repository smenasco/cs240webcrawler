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


class XMLGenerator{
private: 
	std::string outputfile;
	
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
	
	enum XMLTagType
	{
		/**
		 * Returned when the token is of the form <x ...>, where "x" could be anything.
		 */
		WEBSITE,
		/**
		 * Returned when the token is of the form </x ...>, where "x" could be anything.
		 */
		TAG_END,
		/**
		 * Returned when the token is a comment tag of the form <!-- -->.
		 */
		COMMENT,
		/**
		 * Returned when the token is not a tag but is some text.
		 */
		TEXT,
		/**
		 * Returned when there are no more tokens to return.
		 */
		END
	};
	
	void WriteTag();
	
public:
	//!  No-arg constructor.  Initializes an empty XMLGenerator
	XMLGenerator();
	

	//!  Constructor.  Initializes an empty XMLGenerator using the filename from the commandline
	//! @param outputfile where to write output to on the commandline
	XMLGenerator(const std::string & outputfile);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	XMLGenerator(const XMLGenerator & other);
	
	
	//!  Destructor
	~XMLGenerator();
	
	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	XMLGenerator& operator =(const XMLGenerator & other);

	//! Tells the XMLGenerator where to write its XML
	//! @param outputfile the name of the fiel
	void setOutputFile(const std::string & outputfile);
	
	
	//! The caller function to begin writing all of the XML to an outputfile
	//!
	//! @throws FileException when there is an error writing to a file
	void WriteXML();
};


#endif