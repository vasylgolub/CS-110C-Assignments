//
//  SortedListHasA.hpp
//  CS 110C Assignment 5: High Scores
//
//  Created by vasyl golub on 3/17/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef SortedListHasA_hpp
#define SortedListHasA_hpp

#include <stdio.h>
#include "SortedListInterface.hpp"
#include "ListInterface.hpp"
#include "Node.hpp"
#include "PrecondViolatedExcep.hpp"

template<class ItemType>
class SortedListHasA : public SortedListInterface<ItemType>
{
private:
    ListInterface<ItemType>* listPtr;
    
public:
    SortedListHasA();
    SortedListHasA(const SortedListHasA<ItemType>& sList);
    virtual ~SortedListHasA();
    
    void insertSorted(const ItemType& newEntry);
    bool removeSorted(const ItemType& anEntry);
    int getPosition(const ItemType& newEntry) const;
    
    // The following methods have the same specifications
    // as given in ListInterface:
    
    bool isEmpty() const;
    int getLength() const;
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);
}; // end SortedListHasA

//#include "SortedListHasA.cpp"
#endif /* SortedListHasA_hpp */
