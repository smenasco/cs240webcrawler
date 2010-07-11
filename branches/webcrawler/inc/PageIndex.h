#ifndef PAGEINDEX_H
#define PAGEINDEX_H
/*
 *  PageIndex.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */
//NOTE: STILL NEEDS TO HAVE URL CHANGED TO URL TYPE AND ADD PARAM TO CONSTUCTOR
//		THAT WILL INITIALIZE THE DESCRIPTION OF THE PAGE

//A PageIndex of visited & indexed pages
//store index of visited pages
/*
 URL url
 if url is not inside pageindex 
	if url is not in pagequeue 
		add to pagequeue
	else 
		already queued to download
 else 
	its was already indexed
 */
#include <string>

//!  PageNode implements a binary search tree node for a HTML Page
class PageNode {
	friend class PageIndex;   //!< PageIndex can access private members of PageNode
	
public:
	
	//!  Constructor
	PageNode(const std::string & v) : url(v), left(NULL), right(NULL) {
	}
	
	//!  Read-only public methods for use by clients of the PageIndex class
	const std::string & GetValue() const {
		return url;
	}
	
	const PageNode * GetLeft() const {
		return left;
	}
	
	PageNode * GetLeft()	{
		return left;
	}
	
	const PageNode * GetRight() const {
		return right;
	}
	
	PageNode * GetRight() {
		return right;
	}
	
private:
	std::string url;			//!< value stored in the node
	std::string description;	//!< string containing the description of the Page
	PageNode * left;			//!< pointer to the node's left child
	PageNode * right;			//!< pointer to the node's right child
};


//!  PageIndex implements a binary search tree
class PageIndex {
private:
	int count;
	PageNode * root;
	
	void InInsert(PageNode * n);
	PageNode * InsertAgain(PageNode * n, const std::string & v);
	PageNode * FindAgain(PageNode * n,const std::string & v) const;
	void Free(PageNode * n);
public:
	
	//!  No-arg constructor.  Initializes an empty PageIndex
	PageIndex();
	
	
	//!  Copy constructor.  Makes a complete copy of its argument
	PageIndex(const PageIndex & other);
	
	
	//!  Destructor
	~PageIndex();
	
	
	//!  Assignment operator.  Makes a complete copy of its argument
	//!  @return Reference to oneself
	PageIndex& operator =(const PageIndex & other);
	
	
	//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
	//!  @note This is useful for PageIndex clients that need to traverse the tree.)
	PageNode * GetRoot();
	
	
	//!  @return true if the PageIndex is empty, or false if the PageIndex is not empty
	bool IsEmpty() const;
	
	
	//!  Removes all values from the PageIndex
	void Clear();
	
	
	//!  @return the number of values in the PageIndex
	int GetSize() const;
	
	
	//!  Inserts value v into the PageIndex
	//!  
	//!  @param v The new value being inserted
	//!
	//!  @return a pointer to the newly inserted node, or NULL if v was already
	//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
	PageNode * Insert(const std::string & v);
	
	
	//!  Searches the tree for value v
	//!  
	//!  @param v The new value being searched for
	//!
	//!  @return a pointer to the node containing v, or NULL if v is not in the tree
	PageNode * Find(const std::string & v) const;
	
	
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