//
//  Stack.cpp
//  CS 110C Assignment 6: Calculator
//
//  Created by vasyl golub on 4/7/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//
#include <iostream>
#include "Stack.hpp"
using namespace std;

template<class ItemType>
Stack<ItemType>::Stack(){
    stack = new ItemType[SIZE];
    count = -1;
    empty = true;
    
}

template<class ItemType>
Stack<ItemType>::~Stack(){
    delete []stack;
}

template<class ItemType>
void Stack<ItemType>::push(ItemType item){
    count = count + 1;
    stack[count] = item;
    empty = false;
}

template<class ItemType>
bool Stack<ItemType>::pop(){
    if (empty) {
        cout<<"the stack is empty"<<endl;
        return 0;
    }else{
    count--;
        if (count < 0) empty = true;
    return 1;
    }
}


template<class ItemType>
ItemType Stack<ItemType>::peek(){
//    cout<<"the stack at position 0 "<<stack[0]<<endl;
    return stack[count];
}


template class Stack<char>;
