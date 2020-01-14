//
//  LinkedList.hpp
//  CS 110C Assignment 5: High Scores
//
//  Created by vasyl golub on 3/17/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>


#include "ListInterface.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int itemCount;           // Current count of list items
    
    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<ItemType>* getNodeAt(int position) const;
    
public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    virtual ~LinkedList();
    
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    
    /** @throw PrecondViolatedExcep if position < 1 or
     position > getLength(). */
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);
    
    /** @throw PrecondViolatedExcep if position < 1 or
     position > getLength(). */
    void setEntry(int position, const ItemType& newEntry)
    throw(PrecondViolatedExcep);
}; // end LinkedList

//#include "LinkedList.cpp"





#endif /* LinkedList_hpp */
