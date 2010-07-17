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
	WordNode(const std::string & v,const std::string & url) 
	:visted(false), value(v), left(NULL), right(NULL) {
		set = new OccurrenceSet();
		set->Insert(url);
	}
	
	//!  Destructor
	~WordNode(){
		delete set;
	}
	
	//!  Read-only public methods for use by clients of the WordIndex class
	const std::string & GetValue() const {
		return value;
	}
	
	WordNode * GetLeft()	{
		return left;
	}
	
	OccurrenceSet * GetSet(){
		return set;
	}
	
	WordNode * GetRight() {
		return right;
	}
	bool IsVisited(){
		return visted;
	}
	void Visit(){
		visted = true;
	}
	
private:
	bool visted;
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
	
	//!  Destructor
	~WordIndex();
	
	
	//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
	//!  @note This is useful for WordIndex clients that need to traverse the tree.)
	WordNode * GetRoot();
	
	
	//!  @return true if the WordIndex is empty, or false if the WordIndex is not empty
	bool IsEmpty() const;
	
	
	//!  Removes all values from the WordIndex
	void Clear();
	
	
	//!  @return the number of values in the WordIndex
	int GetSize() const;
	
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
	
	//!  Inserts value a word after into the WordIndex
	//!  
	//!  @param v The new value being inserted
	//!
	//!  @return a pointer to the newly inserted node or the node 
	//!   that currently has its word so you can add an occurence to the wordnode->OccurenceSet
	void Insert(const std::string & v,const std::string & url);
	
private:
	int count;
	WordNode * root;
	StopWords * stopWords;		//! pointer to the StopWordsFile
	void InsertAgain(WordNode * n, const std::string & v,const std::string & url);
	WordNode * FindAgain(WordNode * n,const std::string & v) const;
	void Free(WordNode * n);	
	
};

#endif
