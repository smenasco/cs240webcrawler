#ifndef CS240_LINKED_LIST_H
#define CS240_LINKED_LIST_H

#include <string>
//! LLNode implements a doubly-linked list node
class LLNode {
	friend class LinkedList;  //!< LinkedList can access private members of LLNode
public:

	//!  Constructor
	LLNode(const std::string & v, LLNode * p, LLNode * n) : value(v), prev(p), next(n){
	}

	//!  Read-only public methods for use by clients of the LinkedList class
	const std::string & GetValue() const
	{
	  return value;
	}

	const LLNode * GetPrevious() const
	{
	  return prev;
	}

	LLNode * GetPrevious()
	{
	  return prev;
	}

	const LLNode * GetNext() const
	{
	  return next;
	}

	LLNode * GetNext()
	{
	  return next;
	}

private:
	std::string value;        //!< value stored in the node
	LLNode * prev;            //!< pointer to previous node in the list
	LLNode * next;            //!< pointer to next node in the list
};


//! LinkedList implements a doubly-linked list
class LinkedList
{
private:
	LLNode * first;
	LLNode * last;
	int count;
	void Free();
	void Init(const LinkedList & other);
public:

	//!  No-arg constructor.  Initializes an empty linked list
	LinkedList();


	//!  Copy constructor.  Makes a complete copy of its argument
	LinkedList(const LinkedList & other);


	//!  Destructor
	~LinkedList();


	//! Assignment operator.  Makes a complete copy of its argument
	//! @return A reference to oneself
	LinkedList& operator =(const LinkedList & other);


	//!  @return true if the list is empty, or false if the list is not empty
	bool IsEmpty() const;


	//!  Removes all values from the list
	void Clear();


	//!  @return the number of values in the list
	int GetSize() const;


	//!  @return a pointer to the first node in the list, or NULL if the list is empty
	const LLNode * GetFirst() const;


	//!  @return a pointer to the first node in the list, or NULL if the list is empty
	LLNode * GetFirst();


	//!  @returns a pointer to the last node in the list, or NULL if the list is empty
	const LLNode * GetLast() const;


	//!  @returns a pointer to the last node in the list, or NULL if the list is empty
	LLNode * GetLast();


	//!  Inserts value v into the list after node n
	//!  
	//!  @param v The new value being inserted
	//!  @param n A node that is already in the list after which the new node should 
	//!      be inserted.
	//!      If n is NULL, the new node should be inserted at the beginning of the list.
	//!
	//!  @return a pointer to the newly inserted node
	LLNode * Insert(const std::string & v, LLNode * n);


	//! Searches for the first occurrence of value v that appears in the list 
	//!   after node n
	//!   
	//!  @param v The value being searched for
	//!  @param n The node in the list after which the search should begin.
	//!      If n is NULL, the list should be searched from the beginning.
	//!
	//!  @return a pointer to the node containing v, or NULL if v is not found
	LLNode * Find(const std::string & v, LLNode * n) const;


	//!  Removes node n from the list
	//!  
	//!  @param n The node being removed from the list
	void Remove(LLNode * n);


};


#endif

