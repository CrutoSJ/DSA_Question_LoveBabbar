// #Question:-

// #Link->  https://www.codingninjas.com/studio/problems/redundant-brackets_975473

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char>stk;

    for(int i=0; i<s.length(); i++){
        char ch=s[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='/' || ch=='*'){
            stk.push(ch);
        }
        
        else{
            if(ch == ')'){
                bool isRedundant = true;
                while(stk.top()!='('){
                    if(stk.top()=='+' || stk.top()=='-' || stk.top()=='/' || stk.top()=='*'){
                        isRedundant = false;
                    }
                    stk.pop();
                }

                if(isRedundant==true){
                    return true;
                }
                stk.pop();
            }
        }
    }
    return false;
}
