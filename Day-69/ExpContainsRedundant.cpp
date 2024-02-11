// #Question:-

// Link- >https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkRedundancy(string s) {
        stack<char>st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*'){
                st.push(ch);
            }
            else{
                if(ch == ')'){
                    bool isRedundant = true;
                    while(st.top() != '('){
                        char top = st.top();
                        if(top == '(' || top == '+' || top == '-' || top == '/' || top == '*'){
                            isRedundant = false;
                        }
                        st.pop();
                    }
                    
                    if(isRedundant == true){
                        return true;
                    }
                    st.pop();
                }
            }
        }
        return false;
    }
};