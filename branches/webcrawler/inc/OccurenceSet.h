#ifndef OCCURENCESET_H
#define OCCURENCESET_H

/*
 *  OccurenceSet.h
 *  project1
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include <string>


//!  OccurenceNode implements a binary search tree node
class OccurenceNode {
	friend class OccurenceSet;   //!< OccurenceSet can access private members of OccurenceNode
	
public:
	
	//!  Constructor
	OccurenceNode(const std::string & v) : value(v), left(NULL), right(NULL) {
	}
	
	//!  Read-only public methods for use by clients of the OccurenceSet class
	const std::string & GetValue() const {
		return value;
	}
	
	const OccurenceNode * GetLeft() const {
		return left;
	}
	
	OccurenceNode * GetLeft()	{
		return left;
	}
	
	const OccurenceNode * GetRight() const {
		return right;
	}
	
	OccurenceNode * GetRight() {
		return right;
	}
	
private:
	std::string value;		  //!< url value stored in the node
	int count;			      //!< the number of times the word appears on the url
	OccurenceNode * left;     //!< pointer to the node's left child
	OccurenceNode * right;    //!< pointer to the node's right child
};


//!  OccurenceSet implements a binary search tree
class OccurenceSet {
private:
	int count;
	OccurenceNode * root;
	
	void InInsert(OccurenceNode * n);
	OccurenceNode * InsertAgain(OccurenceNode * n, const std::string & v);
	OccurenceNode * FindAgain(OccurenceNode * n,const std::string & v) const;
	void Free(OccurenceNode * n);
public:
	
	//!  No-arg constructor.  Initializes an empty OccurenceSet
	OccurenceSet();
	
	
	//!  Copy constructor.  Makes a complete copy of its argument
	OccurenceSet(const OccurenceSet & other);
	
	
	//!  Destructor
	~OccurenceSet();
	
	
	//!  Assignment operator.  Makes a complete copy of its argument
	//!  @return Reference to oneself
	OccurenceSet& operator =(const OccurenceSet & other);
	
	
	//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
	//!  @note This is useful for OccurenceSet clients that need to traverse the tree.)
	OccurenceNode * GetRoot();
	
	
	//!  @return true if the OccurenceSet is empty, or false if the OccurenceSet is not empty
	bool IsEmpty() const;
	
	
	//!  Removes all values from the OccurenceSet
	void Clear();
	
	
	//!  @return the number of values in the OccurenceSet
	int GetSize() const;
	
	
	//!  Inserts value v into the OccurenceSet
	//!  
	//!  @param v The new value being inserted
	//!
	//!  @return a pointer to the newly inserted node, or NULL if v was already
	//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
	OccurenceNode * Insert(const std::string & v);
	
	
	//!  Searches the tree for value v
	//!  
	//!  @param v The new value being searched for
	//!
	//!  @return a pointer to the node containing v, or NULL if v is not in the tree
	OccurenceNode * Find(const std::string & v) const;
	
	
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
