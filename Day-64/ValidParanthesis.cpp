// #Question:-

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            //for opening brackets:-
            if(ch == '{' || ch == '(' || ch == '['){
                stk.push(ch);
            }
            
            //for closing brackets:-
            else{
                if(!stk.empty()){
                        char top = stk.top();
                        if( ch == ')' && top == '(' ||
                            ch == '}' && top == '{' ||
                            ch == ']' && top == '['){
                            stk.pop();
                        }
                        else{
                            return false;
                        }
                }
                else{
                    return false;
                }
            }
        }
        
        if(stk.empty()){
            return true;
        }
        
        return false;
    }
};
