#ifndef PAGEQUEUE_H
#define PAGEQUEUE_H
/*
 *  URLQueue.h
 *  
 *
 *  Created by Sam on 7/10/10.
 *  Copyright 2010 Samuel Menasco. All rights reserved.
 *
 */



#include <string>

class URLNode {
	friend class URLQueue;  //!< URLQueue can access private members of URLNode
private:
	URLNode * prev;		   	//!< previous node in the stack
public:
	
	//! Constructor
	//!
	//! @param v string to be placed in the node.
	URLNode(const std::string & v);
	
	
	//! Constructor
	//!
	//! @param v string to be placed in the node.
	//! @param p previous node in the stack
	URLNode(const std::string & v, URLNode * p);
	
	std::string value;		//!< the value of the url in the node
	
	
	
};


//! URLQueue Implements a LIFO queue, aka. stack
//! DOES NOT ALLOW DUPLICATES

class URLQueue {
private:
	URLNode * top;
	int count;			//!< contains the current number of URLs on the stack

	//! Method that implements destructor
	void Free();	

	//! Method that implements constructor to be called from copy constructor and = operator
	void Init(const URLQueue & other);
	
public:
	//! No-arg Constructor.  creates an empty URLQueue
	URLQueue();
	
	//! Copy constructor.  Makes a complete copy of its argument 
	URLQueue(const URLQueue & other);
	
	//!  Assignment operator.  Makes a complete copy of its argument
	//!  @return Reference to oneself
	URLQueue & operator =(const URLQueue & other);
	
	//! Destructor
	~URLQueue();
	
	//! Push a new URL onto the stack
	//!
	//! @param v value to be pushed onto the stack
	//! @return a pointer to the newly inserted node, or NULL if v was already
	//!          in the stack (i.e., NULL is used to indicate a duplicate insertion)
	URLNode * Push(const std::string & v);
	
	//! @return url at the top of the stack, or NULL if stack is empty
	const std::string & Top() const;
	
	//! @return string to url at top of stack and removes value from stack, or NULL if the stack is empty.
	std::string Pop();
	
	//! @return the number of items on the stack of urls
	int GetCount() const;
	
	//! @return TRUE if the stack is empty
	bool IsEmpty() const;
	
};




#endif