// #Question:-

// Link -> https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/651074/offering/10442135

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<int> st;
    for(char c : s) {
       if(c == '(' || c == '{' || c == '[') {
           st.push(c);
       } 
       else
        {
           if (st.empty() || (c == ')' && st.top() != '(') ||
               (c == '}' && st.top() != '{') || (c == ']' && st.top() != '[')) {
             return false;
           }
           st.pop();
       }
   }
    return st.empty();
};