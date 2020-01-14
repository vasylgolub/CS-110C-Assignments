//
//  Dictionary.hpp
//  CS 110C Assignment 10: Birthdays
//
//  Created by vasyl golub on 5/7/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <regex>
#include "Heap.hpp"
#include "Person.hpp"
using namespace std;

template <class KeyType, class ItemType>
class Dictionary : public Heap<KeyType> {
    KeyType key;
    ItemType item;
    Heap<Person> heapArray;
public:
    Dictionary(){}
    Dictionary(KeyType k, ItemType i){
        Person pers(k,i);
        heapArray.add(pers);
        
    }
    
    
    bool addEntry(KeyType k, ItemType i){
        Person pers(k,i);
        heapArray.add(pers);
        return true;
    }
    bool remove(Person p){
        heapArray.remove(p);
        return true;
    }
    bool remove(KeyType k, ItemType i){
        Person person(k,i);
        heapArray.remove(person);
        return true;
    }
    void viewList(){
        heapArray.viewList();
    }
    
    
  
    ItemType getBirthdayDate(KeyType k){
        
       Person *p =  heapArray.getItems();
        int count = heapArray.getCountItems();
        int posFound = -1;

        for (int i = 0; i<=count; i++) {
            if (k == p[i].getName())
                posFound = i;
        }
        
        if (posFound == -1) {
           throw std::invalid_argument( "Person not found" );
        }
        
        return p[posFound].getDateOfBirth();
        
    }
    
    void listOfSameMonth(int month){
        int matchedMonth = 0;
        regex r("\\d+"); smatch m;
        Person *p =  heapArray.getItems();
        int count = heapArray.getCountItems();
        
        for (int i = 0; i<=count; i++) {
            regex_search(p[i].getDateOfBirth(),m,r);
            for(auto i:m)matchedMonth = stoi(i);
            if (month == matchedMonth)
                cout<<p[i].getName()<<endl;
            matchedMonth = 0;

        }
        
        
        

    }
    
    
};

#endif /* Dictionary_hpp */
