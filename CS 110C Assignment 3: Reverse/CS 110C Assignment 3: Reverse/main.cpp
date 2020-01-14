//
//  main.cpp
//  CS 110C Assignment 3: Reverse
//
//  Created by vasyl golub on 2/17/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedList.hpp" // ADT list operations
#include "PrecondViolatedExcep.hpp"

using namespace std;

void displayList(ListInterface<string>* listPtr)
{
    cout << "The list contains " << endl;
    for (int pos = 1; pos <= listPtr->getLength(); pos++)
    {
        cout << listPtr->getEntry(pos) << " ";
    } // end for
    cout << endl << endl;
}  // end displayList




void listTester()
{
    
    ListInterface<string>* listPtr = new LinkedList<string>();
    cout << "Testing the Link-Based List:" << endl;
    string data[] = {"one", "two", "three", "four", "five", "six"};
    cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
    for (int i = 0; i < 6; i++)
    {
        if (listPtr->insert(i + 1, data[i]))
            cout << "Inserted " << listPtr->getEntry(i + 1)
            << " at position " << (i + 1) << endl;
        else
            cout << "Cannot insert " << data[i] << " at position " << (i + 1)
            << endl;
    }  // end for
    
    displayList(listPtr);
    
    cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
    cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;
    
    cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
    cout << "After replacing the entry at position 3 with XXX: ";
    listPtr->setEntry(3, "XXX");
    displayList(listPtr);
    
} // end listTester





int main()
{
    listTester();
    
    
    
    
    ListInterface<string> *myList = new LinkedList<string>();
    
    
    myList->insert(1, "first");

    myList->insert(2, "second");

    myList->insert(3, "third");
    
    myList->insert(4, "fourth");
    cout<<"List: "<<endl;
    cout<<"Node1["<<myList->getEntry(1)<<"]"<<endl;
    cout<<"Node2["<<myList->getEntry(2)<<"]"<<endl;
    cout<<"Node3["<<myList->getEntry(3)<<"]"<<endl;
    cout<<"Node4["<<myList->getEntry(4)<<"]"<<endl;
    
    myList->reverse();cout<<endl;
    cout<<"List after the reverse function: "<<endl;
    cout<<"Node1["<<myList->getEntry(1)<<"]"<<endl;
    cout<<"Node2["<<myList->getEntry(2)<<"]"<<endl;
    cout<<"Node3["<<myList->getEntry(3)<<"]"<<endl;
    cout<<"Node4["<<myList->getEntry(4)<<"]"<<endl;
    
    
    
    return 0;
}  // end main















