/*
 *  WordIndex.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "WordIndex.h"
#include <string>


//! call delete on all the elements in the WordIndex
void WordIndex::Free(WordNode * n) {
	if (n == NULL) 
		return;
	if(n->left != NULL)
		Free(n->left);
	if(n->right != NULL)
		Free(n->right);
	delete n;
	count = 0;
}

//!  Constructor.  Initializes an empty WordIndex with a pointer to StopWords
WordIndex::WordIndex(StopWords	* sw) : count(0), root(0), stopWords(sw){
	
}

//!  Destructor
WordIndex::~WordIndex() {
	Free(root);
}

//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
//!  @note This is useful for WordIndex clients that need to traverse the tree.)
WordNode * WordIndex::GetRoot() {
	if (IsEmpty())
		return NULL;
	return root;
}


//!  @return true if the WordIndex is empty, or false if the WordIndex is not empty
bool WordIndex::IsEmpty() const {
	return (count ==0);
}


//!  Removes all values from the WordIndex
void WordIndex::Clear() {
	Free(root);
	root = 0;
	count =0;
}


//!  @return the number of values in the WordIndex
int WordIndex::GetSize() const {
	return count;
}


//!  Inserts value v into the WordIndex
//!  
//!  @param v The new value being inserted
//!
//!  @return a pointer to the newly inserted node, or NULL if v was already
//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)


void WordIndex::InsertAgain(WordNode * n, const std::string & v,const std::string & url) {
	if (n == NULL) {
		n = new WordNode(v,url);
		return;
	}
	
	if (v == n->value){
		//add an Occurence of this word 
		n->set->Insert(url);
		
		return;
	}
		
	if (v > n->value){
		if (n->right == NULL) {
			n->right = new WordNode(v,url);
			count++;
			return;
		} else
			InsertAgain(n->right,v,url);
		
	} else {
		if (n->left == NULL){
			n->left = new WordNode(v,url);
			count++;
			return;
		} else
			InsertAgain(n->left,v,url);
	}
}

void WordIndex::Insert(const std::string & v,const std::string & url) {
	if (stopWords->IsStopWord(v)){
		return;
	}
	if (root == NULL) {
		root = new WordNode(v,url);
		count++;
		return;
	}
	InsertAgain(root,v,url);
}


//!  Searches the tree for value v
//!  
//!  @param v The new value being searched for
//!
//!  @return a pointer to the node containing v, or NULL if v is not in the tree
WordNode * WordIndex::FindAgain(WordNode * n,const std::string & v) const {
	if (n == NULL)
		return NULL;
	if (n->value == v)
		return n;
	if (v > n->value) {
		return FindAgain(n->right,v);
	} else
		return FindAgain(n->left,v);
}

WordNode * WordIndex::Find(const std::string & v) const {
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
/*bool WordIndex::Remove(const std::string & v) {
 }*/

