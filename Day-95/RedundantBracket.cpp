// #Question:-

// Link-> https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/651074/offering/10442136

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> myStack;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' or ch == '/') {
            myStack.push(ch);
        } else if (ch == ')') {
            if (myStack.top() == '(') {
                return true;
            } else {
                while (myStack.top() != '(') {
                    myStack.pop();
                }
                myStack.pop();
            }
        }
    }

    return false;
}
