//
//  Node.hpp
//  CS 110C Assignment 3: Reverse
//
//  Created by vasyl golub on 2/24/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
    ItemType        item; // A data item
    Node<ItemType>* next; // Pointer to next node
    Node<ItemType>* previous;//Pointer to the previous node
    
public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr, Node<ItemType>* previousNodePtr);
    
    
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    void setPrevious(Node<ItemType>* previoiusNodePtr);//previous pointer setting
    ItemType getItem() const ;
    Node<ItemType>* getNext() const ;
    Node<ItemType>* getPrevious() const; //get previous pointer
}; // end Node

#endif
