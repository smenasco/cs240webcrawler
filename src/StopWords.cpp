/*
 *  StopWords.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "StopWords.h"


//!  No-arg constructor.  Initializes an empty StopWords
StopWords::StopWords(){
	
}

//!  Constructor with a url that needs resolved
//!
//!  @param filelocation string containing the location of the file to load
StopWords::StopWords(const std::string & filelocation){
	
}

//!  Copy constructor.  Makes a complete copy of its argument
StopWords::StopWords(const StopWords & other){
	
}


//!  Destructor
StopWords::~StopWords(){
	
}


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
StopWords& StopWords::operator =(const StopWords & other){
	
}


//! Load the stopwords file into dynamically sized array
//!
//! @param file the filename to look for in the current working directory to be loaded into array
void StopWords::Load(const std::string & file){
	/*  This is a way to dynamically allocate an array by way of expanding the array
	 int max = 10;           // no longer const
	 int* a = new int[max];  // allocated on heap
	 int n = 0;
	 
	 //--- Read into the array
	 while (cin >> a[n]) {
	 n++;
	 if (n >= max) {
	 max = max * 2;            // double the previous size
	 int* temp = new int[max]; // create new bigger array.
	 for (int i=0; i<n; i++) {
	 temp[i] = a[i];       // copy values to new array.
	 }
	 delete [] a;              // free old array memory.
	 a = temp;                 // now a points to new array.
	 }         
	 }
	 //--- Write out the array etc.
	 */
}

//! Find string in Array of StopWords
//! Implements a binary search through an array
//! @param word the existance of the word that we are interested in
//!
//! @return return the stopword if it was found, else return NULL
const std::string & StopWords::Find(const std::string & word) const{
	
		// function:
		// int binarySearch(int sortedArray[], int first, int last, int key) {
		//   Searches sortedArray[first]..sortedArray[last] for key.  
		// returns: index of the matching element if it finds key, 
		//         otherwise  -(index where it could be inserted)-1.
		// parameters:
		//   sortedArray in  array of sorted (ascending) values.
		//   first, last in  lower and upper subscript bounds
		//   key         in  value to search for.
		// returns:
		//   index of key, or -insertion_position -1 if key is not 
		//                 in the array. This value can easily be
		//                 transformed into the position to insert it.
		
	/*	Example of binary search to model from
		
		while (first <= last) {
			int mid = (first + last) / 2;  // compute mid point.
			if (key > sortedArray[mid]) 
				first = mid + 1;  // repeat search in top half.
			else if (key < sortedArray[mid]) 
				last = mid - 1; // repeat search in bottom half.
			else
				return mid;     // found it. return position /////
		}
		return -(first + 1);    // failed to find key
	*/
}

