//
//  Stack.hpp
//  CS 110C Assignment 6: Calculator
//
//  Created by vasyl golub on 4/7/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp



#include <stdio.h>
template <class ItemType>
class Stack {
private:
    static const int SIZE = 20;
    ItemType* stack;
    int count;
    bool empty;
public:
    Stack();
    ~Stack();
    void push(ItemType item);
    bool pop();
    ItemType peek();
    int getc(){
        return count;
    }
    bool isempty(){
        return empty;
    }
};
#endif /* Stack_hpp */
