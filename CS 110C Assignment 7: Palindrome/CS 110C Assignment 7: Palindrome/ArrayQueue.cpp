//
//  ArrayQueue.cpp
//  CS 110C Assignment 7: Palindrome
//
//  Created by vasyl golub on 4/13/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include "ArrayQueue.hpp"
ArrayQueue::ArrayQueue(){
    count = 0; front = 0; dequeueTimes=1; position=0;
}



bool ArrayQueue::enqueue(char newEntry){
    
    if (count == MAX-1) {
        cout<<"the array is full!"<<endl;
        return false;
    }else{
        count++;
        
        
        if (position >= MAX-1) {
            position = 1;
            items[position]=newEntry;
            front = position -(position -dequeueTimes);
        }else{
            position++;
            items[position]=newEntry;
            front = position -(position -dequeueTimes);
        }
        
    }
    
    return true;
}


bool ArrayQueue::dequeue(){
    
    
    if (count == 0) {
        cout<<"the array is empty!"<<endl;
        return false;
    }else{
        count--;
        
        if (dequeueTimes == MAX-1) {
            dequeueTimes = 1;
            front = position -(position -dequeueTimes);
        }else{
            dequeueTimes++;
            front = position -(position -dequeueTimes);
        }
        
        
    }
    
    
    return true;
}






char ArrayQueue::peekFront(){
    if (isEmpty()) {
        cout<<"the array is empty!"<<endl;
    }else{
        return items[front];
    }
    return 0;
}
