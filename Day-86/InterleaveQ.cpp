// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        stack<int>st;
        vector<int>ans;
        int n = q.size();
        for(int i=0; i<n/2; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        for(int i=0; i<n/2; i++){
            q.push(q.front());
            q.pop();
        }
        
        for(int i=0; i<n/2; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};