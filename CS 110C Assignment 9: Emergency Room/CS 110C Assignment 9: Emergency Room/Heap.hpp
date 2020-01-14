//
//  Heap.hpp
//  CS 110C Assignment 9: Emergency Room
//
//  Created by vasyl golub on 5/2/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp
#include <iterator>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

template <class ItemType>
class Heap {
    static const int ROOT_INDEX = 0;
    ItemType *items;
    int maxItems;
    int index;
    
    

    int getRightChildIndex(int nodeIndex){
        return ((nodeIndex+1)*2);
    }
    int getLeftChildIndex(int nodeIndex){
        return ((nodeIndex+1)*2)-1;
    }
    
    int getParentIndex(int nodeIndex){
        return (nodeIndex-1)/2;
        
    }
    
    
    void heapRebuild(int root, ItemType arr[], int ItemCount){
        if(isLeaf(root) == 0){
            int largeChildIndex = getLeftChildIndex(root);
            
            if (getRightChildIndex(root)<=(index-1)){//does the root has a right child?
                if(items[getRightChildIndex(root)]>items[largeChildIndex])
                largeChildIndex = getRightChildIndex(root);
            }
            if (items[root]<items[largeChildIndex]){
                swap(items[root], items[largeChildIndex]);
                heapRebuild(largeChildIndex, arr, ItemCount);
            }
        
        }
    }
    
    
    void swap(ItemType& x , ItemType& y){
        ItemType z;
        z = x;
        x = y;
        y = z;
    }
    
    bool isLeaf(int nodeIndex){
        if (getLeftChildIndex(nodeIndex) <= (index-1))
            return false;
        if(getRightChildIndex(nodeIndex) <= (index-1))
            return false;
        return true;
    }

public:
    
    
    
    void viewList(){
        for (int i = 0; i<index; i++) {
            cout<<items[i]<<endl;
        }
    }
   
    
    
    Heap(){
        maxItems = 10;
        index = 0;
        items = new ItemType[maxItems];
    }
    Heap(int max){
        maxItems = max;
        index = 0;
        items = new ItemType[maxItems];
    }
    int getHight(){
        return (int)log2(index)+1;
    }
    
    
    
    bool add(ItemType item){
        
        if(index == maxItems) return false;
          items[index] = item;
        int newDataIndex = index;
        bool inPlace = false;
        while ((newDataIndex > 0) && !inPlace) {
            int parentIndex = getParentIndex(newDataIndex);
            if (items[newDataIndex]<items[parentIndex])
                inPlace = true;
            else{
                swap(items[newDataIndex], items[parentIndex]);
                newDataIndex = parentIndex;
            }
        }
        index++;
        return 1;
    }
    
    
    ItemType peekTop(){
        return items[ROOT_INDEX];
    }
    
    
    bool remove(){
        items[ROOT_INDEX] = items[index-1];
        index--;
    
            heapRebuild(ROOT_INDEX, items, index-1);
        
        
        
        
        return true;
    }
};

#endif /* Heap_hpp */








