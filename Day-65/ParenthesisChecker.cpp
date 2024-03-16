// #Question:-

// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The drive code prints "balanced" if function return true, otherwise it prints "not balanced".

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int i=0; i<x.length(); i++){
            char ch = x[i];
            
            if(ch == '{' || ch == '[' || ch == '('){
                s.push(ch);
            } 
            
            else{
                if(!s.empty()){
                    if(ch == '}' && s.top() == '{' ||
                       ch == ']' && s.top() == '[' ||
                       ch == ')' && s.top() == '('){
                           s.pop();
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
        
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }

};