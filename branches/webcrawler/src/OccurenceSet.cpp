/*
 *  OccurenceSet.cpp
 *  project1
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "OccurenceSet.h"
#include <string>


//! Initialize a new OccurenceSet from ref & other
void OccurenceSet::InInsert(OccurenceNode * n){
	if (n == NULL) {
		return;
	} 
	Insert(n->value);
	if(n->left != NULL)
		InInsert(n->left);
	if(n->right != NULL)
		InInsert(n->right);
}
//! call delete on all the elements in the OccurenceSet
void OccurenceSet::Free(OccurenceNode * n) {
	if (n == NULL) 
		return;
	if(n->left != NULL)
		Free(n->left);
	if(n->right != NULL)
		Free(n->right);
	delete n;
	count = 0;
}
OccurenceSet::OccurenceSet() : count(0), root(0){
	return;
}


//!  Copy constructor.  Makes a complete copy of its argument
OccurenceSet::OccurenceSet(const OccurenceSet & other){
	root = 0;
	count = 0;
	OccurenceNode * n = other.root;
	InInsert(n);
}

//!  Destructor
OccurenceSet::~OccurenceSet() {
	Free(root);
}


//!  Assignment operator.  Makes a complete copy of its argument
//!  @return Reference to oneself
OccurenceSet& OccurenceSet::operator =(const OccurenceSet & other){
	if (this != &other) {
		OccurenceNode * n = other.root;
		Free(root);
		root=NULL;
		count=0;
		InInsert(n);
	}
	return *this;
}


//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
//!  @note This is useful for OccurenceSet clients that need to traverse the tree.)
OccurenceNode * OccurenceSet::GetRoot() {
	if (IsEmpty())
		return NULL;
	return root;
}


//!  @return true if the OccurenceSet is empty, or false if the OccurenceSet is not empty
bool OccurenceSet::IsEmpty() const {
	return (count ==0);
}


//!  Removes all values from the OccurenceSet
void OccurenceSet::Clear() {
	Free(root);
	root = 0;
	count =0;
}


//!  @return the number of values in the OccurenceSet
int OccurenceSet::GetSize() const {
	return count;
}


//!  Inserts value v into the OccurenceSet
//!  
//!  @param v The new value being inserted
//!
//!  @return a pointer to the newly inserted node, or NULL if v was already
//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)


OccurenceNode * OccurenceSet::InsertAgain(OccurenceNode * n, const std::string & v) {
	if (n == NULL) {
		n = new OccurenceNode(v);
		return n;
	}
	
	if (v == n->value)
		return NULL;
	if (v > n->value){
		if (n->right == NULL) {
			n->right = new OccurenceNode(v);
			count++;
			return n->right;
		} else
			return InsertAgain(n->right,v);
		
	} else {
		if (n->left == NULL){
			n->left = new OccurenceNode(v);
			count++;
			return n->left;
		} else
			return InsertAgain(n->left,v);
	}
}

OccurenceNode * OccurenceSet::Insert(const std::string & v) {
	if (root == NULL) {
		root = new OccurenceNode(v);
		count++;
		return root;
	}
	return InsertAgain(root,v);
}


//!  Searches the tree for value v
//!  
//!  @param v The new value being searched for
//!
//!  @return a pointer to the node containing v, or NULL if v is not in the tree
OccurenceNode * OccurenceSet::FindAgain(OccurenceNode * n,const std::string & v) const {
	if (n == NULL)
		return NULL;
	if (n->value == v)
		return n;
	if (v > n->value) {
		return FindAgain(n->right,v);
	} else
		return FindAgain(n->left,v);
}

OccurenceNode * OccurenceSet::Find(const std::string & v) const {
	return FindAgain(root,v);
}


//! @NOTE: YOU ARE NOT REQUIRED TO IMPLEMENT THE Remove METHOD BELOW
//!        (BUT YOU CAN IF YOU WANT TO)
//!
//!  Removes value v from the tree
//!  
//!  @param v The value being removed from the tree
//!
//!  @return true if v was removed from the tree, or false if v was not in the tree
/*bool OccurenceSet::Remove(const std::string & v) {
 }*/

