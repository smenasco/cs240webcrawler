/*
 *  OccurrenceSet.cpp
 *  project1
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "OccurrenceSet.h"



//! call delete on all the elements in the OccurrenceSet
void OccurrenceSet::Free(OccurrenceNode * n) {
	if (n == NULL) 
		return;
	if(n->left != NULL)
		Free(n->left);
	if(n->right != NULL)
		Free(n->right);
	delete n;
	count = 0;
}
OccurrenceSet::OccurrenceSet() : count(0), root(0){
	return;
}


//!  Destructor
OccurrenceSet::~OccurrenceSet() {
	Free(root);
}


//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
//!  @note This is useful for OccurrenceSet clients that need to traverse the tree.)
OccurrenceNode * OccurrenceSet::GetRoot() {
	if (IsEmpty())
		return NULL;
	return root;
}


//!  @return true if the OccurrenceSet is empty, or false if the OccurrenceSet is not empty
bool OccurrenceSet::IsEmpty() const {
	return (count ==0);
}


//!  Removes all values from the OccurrenceSet
void OccurrenceSet::Clear() {
	Free(root);
	root = 0;
	count =0;
}


//!  @return the number of values in the OccurrenceSet
int OccurrenceSet::GetSize() const {
	return count;
}


//!  Inserts value v into the OccurrenceSet
//!  
//!  @param v The new value being inserted
//!
//!  @return a pointer to the newly inserted node, or NULL if v was already
//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)


void OccurrenceSet::InsertAgain(OccurrenceNode * n, const std::string & v) {
	if (n == NULL) {
		n = new OccurrenceNode(v);
		return;
	}
	
	if (v == n->value){
		n->count++;
		
	}
	if (v > n->value){
		if (n->right == NULL) {
			n->right = new OccurrenceNode(v);
			count++;
			return;
		} else
			InsertAgain(n->right,v);
		
	} else {
		if (n->left == NULL){
			n->left = new OccurrenceNode(v);
			count++;
			return;
		} else
			InsertAgain(n->left,v);
	}
}

void OccurrenceSet::Insert(const std::string & v) {
	if (root == NULL) {
		root = new OccurrenceNode(v);
		count++;
		return;
	}
	InsertAgain(root,v);
}


//!  Searches the tree for value v
//!  
//!  @param v The new value being searched for
//!
//!  @return a pointer to the node containing v, or NULL if v is not in the tree
OccurrenceNode * OccurrenceSet::FindAgain(OccurrenceNode * n,const std::string & v) const {
	if (n == NULL)
		return NULL;
	if (n->value == v)
		return n;
	if (v > n->value) {
		return FindAgain(n->right,v);
	} else
		return FindAgain(n->left,v);
}

OccurrenceNode * OccurrenceSet::Find(const std::string & v) const {
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
/*bool OccurrenceSet::Remove(const std::string & v) {
 }*/

