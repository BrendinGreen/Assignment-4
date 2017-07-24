/*
 * BST.h
 * 
 * Description: Data collection Binary Search Tree ADT class.
 *              Link-based implementation.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: July 2017
 */

#pragma once

#include "BSTNode.h"
#include "ElementAlreadyExistsInBSTException.h"
#include "ElementDoesNotExistInBSTException.h"


template <class ElementType>
class BST {
	
private:

	BSTNode<ElementType>* root; 
    int elementCount;           

    //Description: Helper for insert
    bool insertR(const ElementType& element, BSTNode<ElementType>* current) ; // throw(ElementAlreadyExistsException);

    //Description: Helper for retrieve
    ElementType& retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const throw(ElementDoesNotExistInBSTException);

    //Description: Helper for traversInOrder
    void traverseInOrderR(void visit(ElementType&), BSTNode<ElementType>* current) const;

    //Description: Helper for copy (basically preOrderTraverse)
    void copyR(BSTNode<ElementType>* current);

    //Description: Helper for destructor (basically postOrderTraversal)
    void deleteR(BSTNode<ElementType>* current);

public:

    // Constructors and destructor:
	BST();                               // Default constructor
    BST(ElementType& element);           // Parameterized constructor 
	BST(const BST<ElementType>& aBST);   // Copy constructor 
    ~BST();                              // Destructor 
	
    // BST operations:

    // Description: Returns the number of elements in the BST
    // Time efficiency: O(1)
	int getElementCount() const;

    // Description: Inserts a new element into the BST
	// Time efficiency: O(log2 n)
    // Pre Condition: Element not already in BST
    // Post Condition: BST is still a Binary Search Tree and element count incrememented by 1
	void insert(const ElementType& newElement) throw(ElementAlreadyExistsInBSTException);	

    // Description: Retrieves a target element from the BST
	// Time efficiency: O(log2 n)
	ElementType& retrieve(const ElementType& targetElement) const throw(ElementDoesNotExistInBSTException);

    // Description: traverse the BST in order and "visit" each element
	// Time efficiency: O(n)
	void traverseInOrder(void visit(ElementType&)) const;
	
}; // end BST

#include "BST.cpp"