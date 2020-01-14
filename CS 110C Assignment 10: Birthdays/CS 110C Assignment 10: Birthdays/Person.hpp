//
//  Person.hpp
//  CS 110C Assignment 10: Birthdays
//
//  Created by vasyl golub on 5/5/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
#include <stdio.h>

using namespace std;
class Person{

    string name;
    string dateOfBirth;//mm/dd/yyyy
    
public:
    
    Person(){
        
    }
    
    Person(string n, string d){
        name = n;
        dateOfBirth = d;
    }
    string getName(){
        return name;
    }
    string getDateOfBirth(){
        return dateOfBirth;
    }
    
    
    bool operator==(const Person& other) const{
        
        if ( other.name==name)
            return 1;
        else
            return 0;
    }
    bool operator>(const Person& other) const{
        if (name > other.name)
            return 1;
        else
            return 0;
    }
    bool operator<(const Person& other) const{
        if (name < other.name)
            return 1;
        else
            return 0;
    }
    
};
#endif /* Person_hpp */
