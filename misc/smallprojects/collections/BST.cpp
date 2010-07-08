#include "BST.h"
#include <string>
using namespace std;


//! Initialize a new BST from ref & other
void BST::InInsert(BSTNode * n){
	if (n == NULL) {
		return;
	} 
	Insert(n->value);
	if(n->left != NULL)
		InInsert(n->left);
	if(n->right != NULL)
		InInsert(n->right);
}
//! call delete on all the elements in the BST
void BST::Free(BSTNode * n) {
	if (n == NULL) 
		return;
	if(n->left != NULL)
		Free(n->left);
	if(n->right != NULL)
		Free(n->right);
	delete n;
	count = 0;
}
BST::BST() : count(0), root(0){
	return;
}


//!  Copy constructor.  Makes a complete copy of its argument
BST::BST(const BST & other){
	root = 0;
	count = 0;
	BSTNode * n = other.root;
	InInsert(n);
}

//!  Destructor
BST::~BST() {
	Free(root);
}


//!  Assignment operator.  Makes a complete copy of its argument
//!  @return Reference to oneself
BST& BST::operator =(const BST & other){
	if (this != &other) {
		BSTNode * n = other.root;
		Free(root);
		root=NULL;
		count=0;
		InInsert(n);
	}
	return *this;
}


//!  @return a pointer to the root node of the tree, or NULL if the tree is empty.
//!  @note This is useful for BST clients that need to traverse the tree.)
BSTNode * BST::GetRoot() {
	if (IsEmpty())
		return NULL;
	return root;
}


//!  @return true if the BST is empty, or false if the BST is not empty
bool BST::IsEmpty() const {
	return (count ==0);
}


//!  Removes all values from the BST
void BST::Clear() {
	Free(root);
	root = 0;
	count =0;
}


//!  @return the number of values in the BST
int BST::GetSize() const {
	return count;
}


//!  Inserts value v into the BST
//!  
//!  @param v The new value being inserted
//!
//!  @return a pointer to the newly inserted node, or NULL if v was already
//!          in the tree (i.e., NULL is used to indicate a duplicate insertion)


BSTNode * BST::InsertAgain(BSTNode * n, const std::string & v) {
	if (n == NULL) {
		n = new BSTNode(v);
		return n;
	}
		
	if (v == n->value)
		return NULL;
	if (v > n->value){
		if (n->right == NULL) {
			n->right = new BSTNode(v);
			count++;
			return n->right;
		} else
			return InsertAgain(n->right,v);
		
	} else {
		if (n->left == NULL){
			n->left = new BSTNode(v);
			count++;
			return n->left;
		} else
			return InsertAgain(n->left,v);
	}
}

BSTNode * BST::Insert(const std::string & v) {
	if (root == NULL) {
		root = new BSTNode(v);
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
BSTNode * BST::FindAgain(BSTNode * n,const std::string & v) const {
	if (n == NULL)
		return NULL;
	if (n->value == v)
		return n;
	if (v > n->value) {
		return FindAgain(n->right,v);
	} else
		return FindAgain(n->left,v);
}

BSTNode * BST::Find(const std::string & v) const {
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
/*bool BST::Remove(const std::string & v) {
}*/
