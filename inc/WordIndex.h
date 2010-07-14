#ifndef WORDINDEX_H
#define WORDINDEX_H
/*
 *  WordIndex.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include <string>
#include "OccurrenceSet.h"
#include "StopWords.h"


//!  WordNode implements a binary search tree node
class WordNode {
	friend class WordIndex;		//!< WordIndex can access private members of WordNode
	
public:
	
	//!  Constructor
	//!  @param v the value to set the WordNode to at initialization 
	WordNode(const std::string & v) : value(v), left(NULL), right(NULL) {
		set = new OccurrenceSet();
	}
	
	//!  Destructor
	~WordNode(){
		delete set;
	}
	
	//!  Read-only public methods for use by clients of the WordIndex class
	const std::string & GetValue() const {
		return value;
	}
	
	const WordNode * GetLeft() const {
		return left;
	}
	
	WordNode * GetLeft()	{
		return left;
	}
	
	OccurrenceSet * GetSet(){
		return set;
	}
	
	const OccurrenceSet * GetSet() const {
		return set;
	}
	
	const WordNode * GetRight() const {
		return right;
	}
	
	WordNode * GetRight() {
		return right;
	}
	
private:
	std::string value;		//!< url value stored in the node
	OccurrenceSet * set;	//!< the set of Occurences that each word maps to.
	WordNode * left;		//!< pointer to the node's left child
	WordNode * right;		//!< pointer to the node's right child
};


//!  WordIndex implements a binary search tree
class WordIndex {

public:
	
	
	//!  Constructor.  Initializes an empty WordIndex with a pointer to StopWords
	WordIndex(StopWords	* sw);
	
	//!  Copy constructor.  Makes a complete copy of its argument
	WordIndex(const WordIndex & other);
	
	
	//!  Destructor
	~WordIndex();
	
	
	//!  Assignment operator.  Makes a complete copy of its argument
	//!  @return Reference to oneself
	WordIndex& operator =(const WordIndex & other);
	
	
	//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
	//!  @note This is useful for WordIndex clients that need to traverse the tree.)
	WordNode * GetRoot();
	
	
	//!  @return true if the WordIndex is empty, or false if the WordIndex is not empty
	bool IsEmpty() const;
	
	
	//!  Removes all values from the WordIndex
	void Clear();
	
	
	//!  @return the number of values in the WordIndex
	int GetSize() const;
	
	
	//!  Inserts value a word after into the WordIndex
	//!  
	//!  @param v The new value being inserted
	//!
	//!  @return a pointer to the newly inserted node or the node 
	//!   that currently has its word so you can add an occurence to the wordnode->OccurenceSet
	WordNode * Insert(const std::string & v);
	
	
	//!  Searches the tree for value v
	//!  
	//!  @param v The new value being searched for
	//!
	//!  @return a pointer to the node containing v, or NULL if v is not in the tree
	WordNode * Find(const std::string & v) const;
	
	
	//! @NOTE: YOU ARE NOT REQUIRED TO IMPLEMENT THE Remove METHOD BELOW
	//!        (BUT YOU CAN IF YOU WANT TO)
	//!
	//!  Removes value v from the tree
	//!  
	//!  @param v The value being removed from the tree
	//!
	//!  @return true if v was removed from the tree, or false if v was not in the tree
	//bool Remove(const std::string & v);
private:
	int count;
	WordNode * root;
	StopWords * stopWords;		//! pointer to the StopWordsFile
	void InInsert(WordNode * n);
	WordNode * InsertAgain(WordNode * n, const std::string & v);
	WordNode * FindAgain(WordNode * n,const std::string & v) const;
	void Free(WordNode * n);	
	
};

#endif
