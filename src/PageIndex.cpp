/*
 *  PageIndex.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "PageIndex.h"

#include <string>



//! Initialize a new PageIndex from ref & other
void PageIndex::InInsert(PageNode * n){
	if (n == NULL) {
		return;
	} 
	Insert(n->url,n->description);
	if(n->left != NULL)
		InInsert(n->left);
	if(n->right != NULL)
		InInsert(n->right);
}
//! call delete on all the elements in the PageIndex
void PageIndex::Free(PageNode * n) {
	if (n == NULL) 
		return;
	if(n->left != NULL)
		Free(n->left);
	if(n->right != NULL)
		Free(n->right);
	delete n;
	count = 0;
}


PageIndex::PageIndex() : count(0), root(0){
	return;
}


//!  Copy constructor.  Makes a complete copy of its argument
PageIndex::PageIndex(const PageIndex & other){
	root = 0;
	count = 0;
	PageNode * n = other.root;
	InInsert(n);
}

//!  Destructor
PageIndex::~PageIndex() {
	Free(root);
}


//!  Assignment operator.  Makes a complete copy of its argument
//!  @return Reference to oneself
PageIndex& PageIndex::operator =(const PageIndex & other){
	if (this != &other) {
		PageNode * n = other.root;
		Free(root);
		root=NULL;
		count=0;
		InInsert(n);
	}
	return *this;
}


//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
//!  @note This is useful for PageIndex clients that need to traverse the tree.)
PageNode * PageIndex::GetRoot() {
	if (IsEmpty())
		return NULL;
	return root;
}


//!  @return true if the PageIndex is empty, or false if the PageIndex is not empty
bool PageIndex::IsEmpty() const {
	return (count ==0);
}


//!  Removes all urls from the PageIndex
void PageIndex::Clear() {
	Free(root);
	root = 0;
	count =0;
}


//!  @return the number of urls in the PageIndex
int PageIndex::GetSize() const {
	return count;
}


//!  Inserts url v into the PageIndex
//!  
//!  @param v The new url being inserted
//!
//!  @return a pointer to the newly inserted node, or NULL if v was already
//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)
PageNode * PageIndex::InsertAgain(PageNode * n, const std::string & v,const std::string & d) {
	if (n == NULL) {
		n = new PageNode(v,d);
		return n;
	}
	
	if (v == n->url)
		return NULL;
	if (v > n->url){
		if (n->right == NULL) {
			n->right = new PageNode(v,d);
			count++;
			return n->right;
		} else
			return InsertAgain(n->right,v,d);
		
	} else {
		if (n->left == NULL){
			n->left = new PageNode(v,d);
			count++;
			return n->left;
		} else
			return InsertAgain(n->left,v,d);
	}
}

PageNode * PageIndex::Insert(const std::string & v,const std::string & d) {
	if (root == NULL) {
		root = new PageNode(v,d);
		count++;
		return root;
	}
	return InsertAgain(root,v,d);
}


//!  Searches the tree for url v
//!  
//!  @param v The new url being searched for
//!
//!  @return a pointer to the node containing v, or NULL if v is not in the tree
PageNode * PageIndex::FindAgain(PageNode * n,const std::string & v) const {
	if (n == NULL)
		return NULL;
	if (n->url == v)
		return n;
	if (v > n->url) {
		return FindAgain(n->right,v);
	} else
		return FindAgain(n->left,v);
}

bool PageIndex::Find(const std::string & v) const {
	PageNode * n = FindAgain(root,v);
	if (n == NULL)
		return false;
	else 
		return true;
}


//! @NOTE: YOU ARE NOT REQUIRED TO IMPLEMENT THE Remove METHOD BELOW
//!        (BUT YOU CAN IF YOU WANT TO)
//!
//!  Removes url v from the tree
//!  
//!  @param v The url being removed from the tree
//!
//!  @return true if v was removed from the tree, or false if v was not in the tree
/*bool PageIndex::Remove(const std::string & v) {
 }*/
