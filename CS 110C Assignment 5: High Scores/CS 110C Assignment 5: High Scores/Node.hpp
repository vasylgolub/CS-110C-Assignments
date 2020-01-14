//
//  Node.hpp
//  CS 110C Assignment 5: High Scores
//
//  Created by vasyl golub on 3/17/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template<class ItemType>
class Node
{
private:
    ItemType        item; // A data item
    Node<ItemType>* next; // Pointer to next node
    
public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType getItem() const ;
    Node<ItemType>* getNext() const ;
}; // end Node

//#include "Node.cpp"




#endif /* Node_hpp */
