//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */
#include <iostream>
#include "LinkedList.hpp"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>


////CONSTRUCTORS"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0), tailPtr(nullptr)
{
    headPtr = nullptr;
    itemCount = 0;
    tailPtr = nullptr;
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
    
    
    Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
    
    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original list is empty
    else
    {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        
        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
        origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();
            
            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            
            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
            
            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while
        
        newChainPtr->setNext(nullptr);              // Flag end of chain
    }  // end if
}  // end copy constructor



template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}  // end destructor
//"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""






template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}  // end getLength




//____________________________Insert_______________________________________________________________
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        
        
        //"""""""empty case"""""""""
        if (itemCount == 0) {
            headPtr = newNodePtr;
            tailPtr = newNodePtr;
        }
        //""""""""""""""""""""""""""
        
        
        //"""""""""""""""first position case"""""""""""""""""""""
        if ((newPosition-1)==0 && (itemCount != 0)) {
            Node<ItemType>* oldNodePtr = getNodeAt(newPosition);//node at chosen position that needs to move for the new one
            headPtr = newNodePtr;
            newNodePtr->setNext(oldNodePtr); // current node to the next node
            oldNodePtr->setPrevious(newNodePtr);//next node to the previous node
        }
        //""""""""""""""""""""""""""""""""""""""""""""""""""""""""

        
        //"""""""""""""""last position case""""""""""""""""""""""""""""""""""""
        if ((newPosition > itemCount) && (itemCount != 0)) {
            
            tailPtr = newNodePtr;
            newNodePtr->setNext(nullptr); // new Node points to nullPtr
            newNodePtr->setPrevious(getNodeAt(newPosition-1));
            getNodeAt(newPosition-1)->setNext(newNodePtr);

        }
        //"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

        
        //"""""""""""""""middle insertion case""""""""""""""""""""""""""""""""""""""""
        if ((newPosition <= itemCount)&&(newPosition>1)) {
            
        
        Node<ItemType>* oldNodePtr = getNodeAt(newPosition);//node at chosen position that needs to move for the new one
        getNodeAt(newPosition-1)->setNext(newNodePtr);//previous node points to the new node
        newNodePtr->setPrevious(getNodeAt(newPosition-1)); //new node point to the node before it
        
        newNodePtr->setNext(oldNodePtr);//new node points to the node that was at the old position,
                                        //example: we choose position of insertion 2, so the node that was at position
                                        //          2 is the oldNode that points to the new node that is taking position 2.
                                        //          oldNode in this case will be at position 3 now.
        oldNodePtr->setPrevious(newNodePtr);
        }
        //""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
        
        
        itemCount++;  // Increase count of entries
    }  // end if
    return ableToInsert;
}  // end insert

//__________________________________________________________________________________________________




template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curPtr = nullptr;
        if (position == 1)
        {
            
            // Remove the first node in the chain
            curPtr = headPtr; // Save pointer to node. Save the node that we need to delete.
            if (itemCount != 1) {//if the node is not the last one left in the list
                headPtr = headPtr->getNext();
                headPtr->setPrevious(nullptr);//node at first position doesn't point to nothing before it.

            }else{//if the node is the last one left in the list we do nothing but reset the headPtr and tailPtr to nullptr
                headPtr = nullptr;
                tailPtr = nullptr;
            }
        }
        else
        {
            // Find node that is before the one to delete
            Node<ItemType>* prevPtr = getNodeAt(position - 1);
            
            // Point to node to delete
            curPtr = prevPtr->getNext();
            
            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            if (position != itemCount){
                 prevPtr->setNext(curPtr->getNext());
                curPtr->getNext()->setPrevious(prevPtr);
            }
            else{
                prevPtr->setNext(nullptr);
                tailPtr = prevPtr;
            }
           
        }  // end if
        
        // Return node to system
        curPtr->setNext(nullptr);
        curPtr->setPrevious(nullptr);
        delete curPtr;
        curPtr = nullptr;
        
        itemCount--;  // Decrease count of entries
    }  // end if
    
    return ableToRemove;
}  // end remove

//   headPtr -> [3] <-> [2] <-> [1] <- tailPtr



template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}  // end clear







template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        string message = "getEntry() called with an empty list or ";
        message  = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end getEntry








template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
    // Enforce precondition
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if (ableToSet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);
    }
    else
    {
        string message = "setEntry() called with an invalid position.";
        throw(PrecondViolatedExcep(message));
    }  // end if
}  // end setEntry





//PRIVET METHOD//==================GetNodeAt================================================
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    if (position > itemCount) return nullptr;//************************************extra
    
    // Debugging check of precondition
    assert( (position >= 1) && (position <= itemCount) );
    
    
    
    
    // Count from the beginning of the chain
    Node<ItemType>* curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();
    
    return curPtr;
}  // end getNodeAt
//============================================================================================





template<class ItemType>
void LinkedList<ItemType>::reverse(){

    Node<ItemType>*justANode = tailPtr;
    tailPtr = headPtr;
    headPtr = justANode;
    
    
    Node<ItemType> Node;
    
    for (int i = 1; i<=itemCount; i++) {
        Node = *(getNodeAt(i));
        getNodeAt(i)->setNext(Node.getPrevious());
        getNodeAt(i)->setPrevious(Node.getNext());
    }
   
    
    
}




// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;
