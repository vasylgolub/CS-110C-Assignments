//
//  ArrayQueue.hpp
//  CS 110C Assignment 7: Palindrome
//
//  Created by vasyl golub on 4/13/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef ArrayQueue_hpp
#define ArrayQueue_hpp

#include <stdio.h>
#include <iostream>
#include "Queue.hpp"
using namespace std;

#endif /* ArrayQueue_hpp */


const int MAX = 6;// the array will actually contain only 5 items;
class ArrayQueue: public Queue{
    
private:
    

    char items[MAX];
    
    int front;
//    int back;
    int count;//count how many items are in the array;
    int dequeueTimes;//count how many times we dequeued
    
    int position;
    
public:
    
   
    ArrayQueue();
    
    
    bool isEmpty(){
        return count == 0;
        position = 0;
    }
    
    
    bool enqueue(char newEntry);
    bool dequeue();
    char peekFront();
    
};

















//void getReport(){
//    cout<<"front = "<<front<<endl;
//    cout<<"position = "<<position<<endl;
//    cout<<"dequeTimes = "<<dequeueTimes<<endl;
//    cout<<"count = "<<count<<endl;
//}















