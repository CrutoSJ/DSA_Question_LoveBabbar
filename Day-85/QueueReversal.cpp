// #Question:-

// Link->  https://www.geeksforgeeks.org/problems/queue-reversal/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int>st;
        
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        return q;
    }
};