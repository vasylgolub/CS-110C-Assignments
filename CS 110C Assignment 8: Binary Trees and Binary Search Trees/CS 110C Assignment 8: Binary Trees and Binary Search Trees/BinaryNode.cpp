//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file BinaryNode.cpp */

#include "BinaryNode.hpp"
#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}  // end default constructor




template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}  // end constructor




template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr,
                                 BinaryNode<ItemType>* rightPtr) : item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
}  // end constructor




template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}  // end setItem







template<class ItemType>
int BinaryNode<ItemType>::level(ItemType target, BinaryNode<ItemType>* nodePtr){
    
    int pos = 1, right = 0, left = 0;
    
    if (nodePtr->getItem() == target) {
        return pos;
    }else if(nodePtr->isLeaf() == false){
        right = level(target, nodePtr->getRightChildPtr());
        left = level(target, nodePtr->getLeftChildPtr());
    }else return 0;
    
    if(right>left) return pos+right;
    else if(left<right)
        return pos+left;
    else return 0;
    
    
    
}








template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item;
}  // end getItem




template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
    return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}






template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
    leftChildPtr = leftPtr;
}  // end setLeftChildPtr



template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
    rightChildPtr = rightPtr;
}  // end setRightChildPtr





template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}  // end getLeftChildPtr




template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}  // end getRightChildPtr




// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use in this .cpp file.
// (just strings and ints for now, add more types if desired)
template class BinaryNode<std::string>;
template class BinaryNode<int>;


