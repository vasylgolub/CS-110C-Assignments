//
//  main.cpp
//  CS 110C Assignment 7: Palindrome
//
//  Created by vasyl golub on 4/12/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "ArrayQueue.hpp"
using namespace std;


bool checkPalindrome(string s){
    Stack<char> stack;
    ArrayQueue myQueue;
    
    for(auto c:s) stack.push(c);
    for(auto c:s) myQueue.enqueue(c);
    
    
    for (int i = 0; i<s.length(); i++) {
        
        
        if (stack.peek() != myQueue.peekFront())return false;
            stack.pop();
            myQueue.dequeue();
    }

    
    
    
    
    return true;
}

int main(int argc, const char * argv[]) {
    
    cout<<"aa:\t\t " <<checkPalindrome("aa")<<endl;
    
    cout<<"aba:\t "<<checkPalindrome("aba")<<endl;

    cout<<"abba:\t "<<checkPalindrome("abba")<<endl;

    cout<<"aabb:\t " <<checkPalindrome("aabb")<<endl;
    
    cout<<"abbaa:\t "<<checkPalindrome("abbaa")<<endl;
    
    cout<<"a:\t\t "<<checkPalindrome("a")<<endl;



    
    
    
    
    return 0;
}
