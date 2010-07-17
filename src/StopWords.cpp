/*
 *  StopWords.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "StopWords.h"

//!  Constructor with a url that needs resolved
//!
//!  @param filelocation string containing the location of the file to load
StopWords::StopWords(const std::string & filelocation){
	Load(filelocation);
}

//!  Destructor
StopWords::~StopWords(){
	delete [] words;  
}


//! Load the stopwords file into dynamically sized array
//!
//! @param file the filename to look for in the current 
//! working directory to be loaded into array
void StopWords::Load(const std::string & filelocation){
	try {
		//std::cout << "filelocation: " << filelocation << std::endl;
		std::ifstream file(filelocation.c_str());
		MAX = 10;
		count = 0;
		words = new std::string[MAX];
		while(file.good()) {
			std::string line;
			getline(file,line);
			//std::cout << "word: " << line << std::endl;
			if (!line.empty())
				AddWord(line);
		}
		
		file.close();	
		
	}
	catch (std::exception &e) {
		std::cout << "StopWords: Exception Occurred:" << e.what() << std::endl;		
	}
	catch (CS240Exception &e) {
		std::cout << "StopWords: Exception Occurred:" << e.GetMessage() << std::endl;
	}
	catch (...) {
		std::cout << "StopWords: Unknown Exception Occurred" << std::endl;		
	}
	

}

void StopWords::AddWord(const std::string & word){
	//  This is a way to dynamically allocate an array by way of expanding the array
	count++;
	if (count >= MAX) {  //if the array is full, expand it so we can cram more words in
		MAX = MAX * 2;            // double the previous size
		std::string * temp = new std::string[MAX]; // create new bigger array.
		for (int i=0; i<count; i++) {
			temp[i] = words[i];       // copy values to new array.
		}
		delete [] words;              // free old array memory.
		words = temp;                 // now a points to new array.
	}
	words[count-1] = word;	//insert the word into the array
}


//! Find string in words , the array of StopWords
//! Implements a binary search through an array
//! @param word the existance of the word that we are interested in
//!
//! @return return TRUE if word was found, else return FALSE
bool StopWords::IsStopWord(const std::string & word){
	int first = 0;
	int last = count;
	while (first <= last) {
		int mid = (first + last) / 2;  // compute mid point.
		if (word > words[mid]) 
			first = mid + 1;  // repeat search in top half.
		else if (word < words[mid]) 
			last = mid - 1; // repeat search in bottom half.
		else
			return true;     // found it. return true;
	}
	return false;    // failed to find word
}

bool StopWords::Test(std::ostream & os) {
	bool success = true;
	
	StopWords sw("/Users/smenasco/Desktop/cs240/project1/webcrawler/stopword.txt");
	TEST( sw.IsStopWord("a")==true);
	TEST( sw.IsStopWord("z")==true);
	TEST( sw.IsStopWord("there")==true);
	TEST(!sw.IsStopWord("sam")==true);
	TEST(!sw.IsStopWord("")==true);
	return success;
}

