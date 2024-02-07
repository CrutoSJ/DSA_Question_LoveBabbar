// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();

    //recurrsive call:-
    solve(s,x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}
