// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/help-classmates--141631/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int>s;
        s.push(-1);
        
        vector<int>ans(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            
            while(s.top() >= curr){
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(curr);
        }
        return ans;
    } 
};