//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.hpp"  // ADT binary tree operations
#include <iostream>
#include <string>

using namespace std;

void display(string& anItem)
{
    cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
    if (success)
        cout << "Done." << endl;
    else
        cout << " Entry not in tree." << endl;
}  // end check








int main()
{
    
    BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();
    tree1->add("10");
    
    tree1->add("20");
    tree1->add("4");
    tree1->add("0");
    tree1->add("12");
    tree1->add("300");

    tree1->contains("4");
    
    
    return 0;
}  // end main



//tree1:
//Displaying item - 10
//Displaying item - 40
//Displaying item - 20
//Displaying item - 30
//
//tree2:
//Displaying item - 10
//Displaying item - 20
//Displaying item - 30
//Displaying item - 40
//Program ended with exit code: 0




//tree1:
//Displaying item - 10
//Displaying item - 30
//Displaying item - 20
//Displaying item - 40
//
//tree2:
//Displaying item - 10
//Displaying item - 20
//Displaying item - 40
//Displaying item - 30
//Program ended with exit code: 0
