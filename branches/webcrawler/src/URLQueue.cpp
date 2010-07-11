/*
 *  URLQueue.cpp
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */

#include "URLQueue.h"

//! Constructor
//!
//! @param v string to be placed in the node.
URLNode::URLNode(const std::string & v) : value(v), prev(0) {
	return;
}

//! Constructor
//!
//! @param v string to be placed in the node.
//! @param p previous node in the stack
URLNode::URLNode(const std::string & v, URLNode * p) : value(v), prev(p) {
	return;
}


//! Method that implements destructor
void URLQueue::Free() {
	while (top != 0) {
		URLNode * n = top;
		top = top->prev;
		delete n;
	}
	count = 0;
}

//! Method that implements constructor to be called from copy constructor and = operator
void URLQueue::Init(const URLQueue & other) {
	top = 0;
	count = other.count;
	
	URLNode * hisCurNode = other.top;
	URLNode * myLastNode = 0;
	
	while (hisCurNode != 0) {
		URLNode * myCopyNode = new URLNode(hisCurNode->value);
		if (myLastNode == 0) {
			top = myCopyNode;
		}
		else {
			myLastNode->prev = myCopyNode;
		}
		myLastNode = myCopyNode;
		hisCurNode = hisCurNode->prev;
	}
}

//! No-arg Constructor.  creates an empty URLQueue
URLQueue::URLQueue() : top(0), count(0) {
	return;
}

//! Copy constructor.  Makes a complete copy of its argument 
URLQueue::URLQueue(const URLQueue & other) {
	Init(other);
}

//!  Assignment operator.  Makes a complete copy of its argument
//!  @return Reference to oneself
void URLQueue::operator =(const URLQueue & other) {
	if (this != &other) {
		Free();
		Init(other);
	}
}

//! Destructor
URLQueue::~URLQueue() {
	Free();
}

//! Push a new URL onto the stack
//!
//! @param v value to be pushed onto the stack
//! @return a pointer to the newly inserted node, or NULL if v was already
//!          in the stack (i.e., NULL is used to indicate a duplicate insertion)
URLNode * URLQueue::Push(const std::string & v) {
	URLNode * temp = top;
	while (temp != 0 && !IsEmpty()) {
		if (v == temp->value)
			return NULL;
		temp = temp->prev;
	}
	top = new URLNode(v, top);
	++count;
	return top;
}

//! @return url at the top of the stack, or NULL if stack is empty
const std::string & URLQueue::Top() const {
	return top->value;
}

//! @return string to url at top of stack and removes value from stack, or NULL if the stack is empty.
std::string URLQueue::Pop() {
	if (this->IsEmpty())
		return NULL;
	std::string v = top->value;
	URLNode * n = top;
	top = top->prev;
	delete n;
	--count;
	return v;
}

//! @return the number of items on the stack of urls
int URLQueue::GetCount() const {
	return count;
}

//! @return TRUE if the stack is empty
bool URLQueue::IsEmpty() const {
	return (count == 0);
}
