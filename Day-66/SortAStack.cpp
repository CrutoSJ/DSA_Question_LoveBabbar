// #Question:-

// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

// Link ->https://www.geeksforgeeks.org/problems/sort-a-stack/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void sortedInsert(stack<int> &s, int num){
    if(s.empty() || (!s.empty() && s.top() < num)){
        s.push(num);
        return ;
    }
    
    int n = s.top();
    s.pop();
    
    sortedInsert(s, num);
    
    s.push(n);
}

void solve(stack<int> &s){
    if(s.empty()){
        return ;
    }
    
    int num = s.top();
    s.pop();
    
    solve(s);
    
    sortedInsert(s, num);
}

void SortedStack :: sort()
{
    solve(s);
}