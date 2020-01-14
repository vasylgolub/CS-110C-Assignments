//
//  main.cpp
//  CS 110C Assignment 10: Birthdays
//
//  Created by vasyl golub on 5/5/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include <iostream>
#include "Person.hpp"
#include "Dictionary.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    

    Dictionary<string, string> people("Stephen","09/21/1991");
    people.addEntry("Alex", "04/23/1889");
    people.addEntry("Frank", "01/04/1999");
    people.addEntry("John", "12/12/2012");
    people.addEntry("Julio", "12/30/1890");
    people.addEntry("Anna", "10/25/2000");
    
    people.viewList();
    
    cout<<endl;
    
    cout<<"When is Frank's birthday?: "<<endl;
    cout<<people.getBirthdayDate("Frank")<<endl;
    
    cout<<endl;
    
    cout<<"Who was born in December? "<<endl;
    people.listOfSameMonth(12);
    
    
    
    return 0;
}
