#ifndef OccurrenceSET_H
#define OccurrenceSET_H

/*
 *  OccurrenceSet.h
 *  project1
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include <string>
#include <iostream>

#define DEBUG
//!  OccurrenceNode implements a binary search tree node
class OccurrenceNode {
	friend class OccurrenceSet;   //!< OccurrenceSet can access private members of OccurrenceNode
	
public:
	
	//!  Constructor
	OccurrenceNode(const std::string & v) : value(v),count(1), left(NULL), right(NULL) {
	}
	
	//!  Read-only public methods for use by clients of the OccurrenceSet class
	const std::string & GetValue() const {
		return value;
	}
	
	//! Return the count to be used for showing number of times a particular word appears on a page
	const int GetCount() const {
		return count;
	}
	
	const OccurrenceNode * GetLeft() const {
		return left;
	}
	
	OccurrenceNode * GetLeft()	{
		return left;
	}
	
	const OccurrenceNode * GetRight() const {
		return right;
	}
	
	OccurrenceNode * GetRight() {
		return right;
	}
	
private:
	std::string value;		  //!< url value stored in the node
	int count;			      //!< the number of times the word appears on the url
	OccurrenceNode * left;     //!< pointer to the node's left child
	OccurrenceNode * right;    //!< pointer to the node's right child
};


//!  OccurrenceSet implements a binary search tree
class OccurrenceSet {

public:
	
	//!  No-arg constructor.  Initializes an empty OccurrenceSet
	OccurrenceSet();
	
	//!  Destructor
	~OccurrenceSet();
	
	
	//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
	//!  @note This is useful for OccurrenceSet clients that need to traverse the tree.)
	OccurrenceNode * GetRoot();
	
	
	//!  @return true if the OccurrenceSet is empty, or false if the OccurrenceSet is not empty
	bool IsEmpty() const;
	
	
	//!  Removes all values from the OccurrenceSet
	void Clear();
	
	
	//!  @return the number of values in the OccurrenceSet
	int GetSize() const;
	
	
	//!  Inserts value v into the OccurrenceSet
	//!  
	//!  @param v The new value being inserted
	//!
	//!  @return a pointer to the newly inserted node, or NULL if v was already
	//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
	void Insert(const std::string & v);
	
	
	//!  Searches the tree for value v
	//!  
	//!  @param v The new value being searched for
	//!
	//!  @return a pointer to the node containing v, or NULL if v is not in the tree
	OccurrenceNode * Find(const std::string & v) const;
	
	
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
	OccurrenceNode * root;
	

	void InsertAgain(OccurrenceNode * n, const std::string & v);
	OccurrenceNode * FindAgain(OccurrenceNode * n,const std::string & v) const;
	void Free(OccurrenceNode * n);	
};


#endif
