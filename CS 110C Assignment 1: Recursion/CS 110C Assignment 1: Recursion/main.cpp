//
//  main.cpp
//  CS 110C Assignment 1: Recursion
//
//  Created by vasyl golub on 1/26/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include <iostream>
using namespace std;

void reverse_digit(int number){
    
    if(number/10 != 0){
        
    cout<<number%10;
    reverse_digit((int)(number / 10.0));
        
    }else{
        cout<<number;
          cout<<endl;
    }
        
    
    
}
void write_backward(string s){
//    cout<<"Enter write_backward with string: "<<s<<endl;

    if (s.empty()) {
//        cout<<"string s is empty"<<endl;
    }else{
//        cout<<"About to write last character of string: "<<s<<endl;
        cout<<s[s.size() - 1]<<endl;
        write_backward(s.substr(0,s.length()-1));
//        cout<<"We are back to the write_backward with string: "<<s<<endl;
    }
    
//    cout<<"Leave write_backward with string: "<<s<<endl<<endl;
    
}
void write_backward2(string s){
//    cout<<"Enter write_backward2 with string: "<<s<<endl;
    if (s.empty()) {
//        cout<<"string s is empty"<<endl;
    }else{
        write_backward2(s.substr(1,s.length()));
//        cout<<"We are back to write_backward2 with string: "<<s<<endl;
//        cout<<"About to write first character of string: "<<s<<endl;
        cout<<s[0]<<endl;
    }
//     cout<<"Leave write_backward2 with string: "<<s<<endl<<endl;
}



int main(int argc, const char * argv[]) {
    int num = 2015;
    reverse_digit(num);
    cout<<endl;
    
    
    string s = "ciao";
    write_backward(s);
    cout<<endl;
    
    
    write_backward2(s);
    cout<<endl;
    
    
   
    return 0;
}
