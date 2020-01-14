//
//  main.cpp
//  CS 110C Assignment 9: Emergency Room
//
//  Created by vasyl golub on 4/21/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include <iostream>
#include "Heap.hpp"

using namespace std;







int main(int argc, const char * argv[]) {

    Heap<string> ER;
    ER.add("5 Bob");
    ER.add("9 Mary");
    ER.add("1 Max");
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    ER.add("3 Julio");
    ER.add("7 Stacy");
    ER.add("4 Paul");
    ER.add("2 Reiko");
    ER.add("6 Jennifer");
    ER.add("5 Chang");
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    cout << ER.peekTop() << " will now see the doctor.\n";
    ER.remove();
    
    cout<<endl<<"Current List of people in waiting room:"<<endl;;
    ER.viewList();
    
    return 0;
}































