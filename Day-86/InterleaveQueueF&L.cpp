// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        queue<int>newq;
        int k = q.size();
        vector<int>ans;
        
        for(int i=0; i<(k/2); i++){
            newq.push(q.front());
            q.pop();
        }
        
        while(!newq.empty()){
            q.push(newq.front());
            newq.pop();
            
            q.push(q.front());
            q.pop();
        }
        
        for(int i=0; i<k; i++){
            ans.push_back(q.front());
            q.pop();
        }
        
        return ans;
    }
};