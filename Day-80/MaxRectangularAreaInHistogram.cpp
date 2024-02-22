// #Question:-

// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, 
// assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

//Link->  https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article 

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long ans = 0;
        
        stack<int> st;
        
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(i);
            }
            else if(arr[st.top()] <= arr[i]){
                st.push(i);
            }
            else{
                int index = st.top();
                st.pop();
                if(st.empty()){
                    ans = max(ans,arr[index]*(i));
                }
                else ans = max(ans,arr[index]*(i-st.top()-1));
                i--;
            }
        }
        
        while(!st.empty()){
            int index = st.top();
            st.pop();
            if(st.empty()){
                ans = max(ans,arr[index]*n);
            }
            else ans = max(ans,arr[index]*(n-st.top()-1));
        }
        
        return ans;
    }
};