//
//  Queue.hpp
//  CS 110C Assignment 7: Palindrome
//
//  Created by vasyl golub on 4/13/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

class Queue{
    private:
    
    
    public:
    
    bool isEmpty();
    bool enqueue(char newEntry);
    bool dequeue();
    char peekFront();
    
};

#endif /* Queue_hpp */


//        virtual bool isEmpty();
//        virtual bool enqueue(const char newEntry);
//        virtual bool dequeue();
//        virtual char peekFront();
