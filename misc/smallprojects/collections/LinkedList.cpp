#include "LinkedList.h"
#include <string>
using namespace std;



//! LinkedList implements a doubly-linked list

//!  No-arg constructor.  Initializes an empty linked list
LinkedList::LinkedList() : first(0), last(0), count(0){
}
//! Call delete on the Linked List through the list.
void LinkedList::Free() {
	while (last != 0) {
		LLNode * n = last;
		last = last->prev;
		delete n;
	}
	count = 0;
	first = 0;
}

//! Initialize the Linked list using a reference to other, a linked list
void LinkedList::Init(const LinkedList & other) {
	first = NULL;
	last = NULL;
	count = 0;
	LLNode * hisCurNode = other.last;
	
	while(hisCurNode)
	{
		Insert(hisCurNode->value,NULL);
		hisCurNode = hisCurNode->prev;
	}
	
}
//!  Copy constructor.  Makes a complete copy of its argument
LinkedList::LinkedList(const LinkedList & other) {
	Init(other);
}


//!  Destructor
LinkedList::~LinkedList() {
	Free();
}


//! Assignment operator.  Makes a complete copy of its argument
//! @return A reference to oneself
LinkedList & LinkedList::operator =(const LinkedList & other) {
	if (this != &other) {
		Free();
		Init(other);
		
	}
	return *this;
}

//!  @return true if the list is empty, or false if the list is not empty
bool LinkedList::IsEmpty() const {
	return (count == 0);
}

//!  Removes all values from the list
void LinkedList::Clear() {
	Free();
}

//!  @return the number of values in the list
int LinkedList::GetSize() const {
	return count;
}

//!  @return a pointer to the first node in the list, or NULL if the list is empty
const LLNode * LinkedList::GetFirst() const {
	if (IsEmpty())
		return NULL;
	return first;
}

//!  @return a pointer to the first node in the list, or NULL if the list is empty
LLNode * LinkedList::GetFirst() {
	if (IsEmpty())
		return NULL;
	return first;
}

//!  @returns a pointer to the last node in the list, or NULL if the list is empty
const LLNode * LinkedList::GetLast() const {
	if (IsEmpty())
		return NULL;
	return last;
}

//!  @returns a pointer to the last node in the list, or NULL if the list is empty
LLNode * LinkedList::GetLast() {
	if (IsEmpty())
		return NULL;
	return last;
}

//!  Inserts value v into the list after node n
//!  
//!  @param v The new value being inserted
//!  @param n A node that is already in the list after which the new node should 
//!      be inserted.
//!      If n is NULL, the new node should be inserted at the beginning of the list.
//!
//!  @return a pointer to the newly inserted node
LLNode * LinkedList::Insert(const std::string & v, LLNode * n) {
	LLNode * newNode = new LLNode(v,NULL,NULL);
	if (n == NULL) {
		if (IsEmpty()){
			last = newNode;
		} else {
			first->prev = newNode;
		}
		newNode->next = first;
		first = newNode;
	} else {
		if (n->next == NULL){
			last = newNode;
		} else {
			n->next->prev = newNode;
			newNode->next = n->next;
		}
		newNode->prev = n;
		n->next = newNode;
	}
	
	count++;
	return newNode;
}

//! Searches for the first occurrence of value v that appears in the list 
//!   after node n
//!   
//!  @param v The value being searched for
//!  @param n The node in the list after which the search should begin.
//!      If n is NULL, the list should be searched from the beginning.
//!
//!  @return a pointer to the node containing v, or NULL if v is not found
LLNode * LinkedList::Find(const std::string & v, LLNode * n) const {
	LLNode * myNode;
	if (n == NULL) {
		myNode = first;
	} else 
		myNode = n->next;
	while(myNode != NULL) {
		if (v == myNode->value)
			break;
		else
			myNode = myNode->next;
	}
	return myNode;
}

//!  Removes node n from the list
//!  
//!  @param n The node being removed from the list
void LinkedList::Remove(LLNode * n) {
	if (n->prev == NULL && n->next != NULL) {			// if n is the first
		n->next->prev = 0;
		first = n->next;
	} else if (n->next == NULL && n->prev != NULL) {	// if n is the last
		n->prev->next = 0;
		last = n->prev;
	} else if (n->next != NULL && n->prev != NULL) {	// if n is in the middle
		n->prev->next = n->next;
		n->next->prev = n->prev;
	} else {											// if n is the only node in the List
		first = 0;
		last = 0;
	}
	count--;
	delete n;
}
