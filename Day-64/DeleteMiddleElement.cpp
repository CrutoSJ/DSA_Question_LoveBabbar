// #Question:-

// Given a stack, delete the middle element of the stack without using any additional data structure.
// Middle element:- floor((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.

// Note: The output shown by the compiler is the stack from top to bottom.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    private:
    
    void solve(stack<int>&s, int size, int count){
        
        if(count == size/2){
            s.pop();
            return ;
        }
        
        int num = s.top();
        s.pop();
        
        solve(s, size, count+1);
        
        s.push(num);
    };
    
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0;
        
        solve(s, sizeOfStack, count);
    }
};