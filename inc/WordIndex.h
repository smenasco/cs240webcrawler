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
#include "OccurenceSet.h"


//!  WordNode implements a binary search tree node
class WordNode {
	friend class WordIndex;   //!< WordIndex can access private members of WordNode
	
public:
	
	//!  Constructor
	WordNode(const std::string & v) : value(v), left(NULL), right(NULL) {
		set = new OccurenceSet();
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
	
	const WordNode * GetRight() const {
		return right;
	}
	
	WordNode * GetRight() {
		return right;
	}
	
private:
	std::string value;		//!< url value stored in the node
	OccurenceSet * set;
	WordNode * left;		//!< pointer to the node's left child
	WordNode * right;		//!< pointer to the node's right child
};


//!  WordIndex implements a binary search tree
class WordIndex {
private:
	int count;
	WordNode * root;
	
	void InInsert(WordNode * n);
	WordNode * InsertAgain(WordNode * n, const std::string & v);
	WordNode * FindAgain(WordNode * n,const std::string & v) const;
	void Free(WordNode * n);
public:
	
	//!  No-arg constructor.  Initializes an empty WordIndex
	WordIndex();
	
	
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
	
	
	//!  Inserts value v into the WordIndex
	//!  
	//!  @param v The new value being inserted
	//!
	//!  @return a pointer to the newly inserted node, or NULL if v was already
	//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
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
	
	
};

#endif