


//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "SortedListHasA.hpp" // ADT sorted list operations

using namespace std;





int main()
{

    SortedListInterface<int>* scoreList = new SortedListHasA<int>();
    int score = 0;
    string answer = "";
    
    cout<<"\t\t\tThe score list is empty."<<endl;
    
    while (score != -1) {
     
       
        
            cout<<"Enter a score you want to add to the list: ";
            cin>>score;
            scoreList->insertSorted(score);
       
        
        
        for (int i = 1; i<=scoreList->getLength(); i++){//displaying
            if (i==scoreList->getLength())
                cout<<scoreList->getEntry(i)<<".";
            else
            cout<<scoreList->getEntry(i)<<", ";
        }
        
        cout<<endl;
        
    }

    
    return 0;
}  // end main



