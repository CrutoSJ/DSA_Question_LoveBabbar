// #Question:-

// You are given a stack St. You have to reverse the stack using recursion.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void insertAtBottom(stack<int> &St, int num){
        if(St.empty()){
            St.push(num);
            return ;
        }
        
        int val = St.top();
        St.pop();
        
        insertAtBottom(St, num);
        
        St.push(val);
    }
public:
    void Reverse(stack<int> &St){
        if(St.empty()){
            return ;
        }
        
        int num = St.top();
        St.pop();
        
        Reverse(St);
        
        insertAtBottom(St, num);
        
    }
};