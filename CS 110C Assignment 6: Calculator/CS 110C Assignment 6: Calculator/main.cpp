//
//  main.cpp
//  CS 110C Assignment 6: Calculator
//
//  Created by vasyl golub on 4/1/17.
//  Copyright © 2017 vasyl golub. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
using namespace std;

//#include <algorithm>
//#include <regex>
//#include <string>
//#include <vector>

bool isBalanced(string s){
    int count = 0;
    for(auto c:s){
        if (c == '(') count++;
        if (c == ')') count--;
    }
    return count == 0? true:false;
}

bool isOperator(char c){
    return (int)c-'0'<0?true:false;
}
bool isGreaterOrEqualPrecedence(char peekedFromStack, char operatorFromString){
    if (peekedFromStack == '*' && operatorFromString == '+') {
        return true;
    }
    if (peekedFromStack == '*' && operatorFromString == '-') {
        return true;
    }
    if (peekedFromStack == '/' && operatorFromString == '+') {
        return true;
    }
    if (peekedFromStack == '/' && operatorFromString == '-') {
        return true;
    }
    if (peekedFromStack == '/' && operatorFromString == '/') {
        return true;
    }
    if (peekedFromStack == '*' && operatorFromString == '*') {
        return true;
    }
    
    else return false;
}
string convertToPostfix(string s){
    Stack<char> operators;
    string res = "";
    
    if (!isBalanced(s)){
        cout<<"The expression is not balanced!"<<endl;
        return "0";
    }
    
    
    for(char c:s){//---------------------------------------------------------------------------------forloop
        if(isOperator(c))
        {//***
            
            if(operators.isempty())
                operators.push(c);
                else if(isGreaterOrEqualPrecedence(operators.peek(), c) || c == ')')
                {
                    while(!operators.isempty() && isGreaterOrEqualPrecedence(operators.peek(), c))
                    {

                        res+=operators.peek();
                        operators.pop();
                        
                    }
                    if (c==')') {
                        while(operators.peek() != '('){
                            res+=operators.peek();
                            operators.pop();
                        }
                        operators.pop();
                        continue;
                    }
                    operators.push(c);
                }
                else operators.push(c);
        }//***
        
        else//it's a number
            res+=c;
        
    }//--------------------------------------------------------------------------------------------endforloop
    
    //append the rest
    while(!operators.isempty()){
        
        res+=operators.peek();
        operators.pop();
    }
    return res;
}
int computeTheOperation(int op1, int op2, char Operator){
    switch (Operator) {
        case '-':
            return op1 - op2;
            break;
        case '+':
            return op1+op2;
            break;
            
        case '*':
            return op1*op2;
            break;
        case '/':
            return op1/op2;
            break;
            
        default:
            break;
    }
    
    return 0;
}
int calculatePostfix(string postfix){
    Stack<char> st;
    int operand1, operand2;
    for(auto c:postfix){
        if (!isOperator(c)) st.push(c);
        else{
            operand2 = (int)(st.peek()-'0');st.pop();
            operand1 = (int)(st.peek()-'0');st.pop();
            st.push((char)(computeTheOperation(operand1, operand2, c)+'0'));
        }
    }
    return (int)(st.peek()-'0');
}




int main(int argc, const char * argv[]) {
    Stack<char> myStack;
    


    string s = "2+3*2";
    cout<<s<<" = ";
    cout<<calculatePostfix(convertToPostfix(s))<<endl;
    cout<<endl;
    
    s = "(2*3)+1";
    cout<<s<<" = ";
    cout<<calculatePostfix(convertToPostfix(s))<<endl;
    cout<<endl;

    s = "(2*3)+(2*2)";
    cout<<s<<" = ";
    cout<<calculatePostfix(convertToPostfix(s))<<endl;
    cout<<endl;
    
    s = "9-(1+3*2)/7";
    cout<<s<<" = ";
    cout<<calculatePostfix(convertToPostfix(s))<<endl;
    cout<<endl;

    s = "(2*3))+1";
    cout<<s<<" = ";
    cout<<calculatePostfix(convertToPostfix(s))<<endl;
    cout<<endl;
    
    
    
    return 0;
}


















