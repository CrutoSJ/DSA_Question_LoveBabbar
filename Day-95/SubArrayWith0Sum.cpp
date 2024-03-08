// #Question:-

// Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum. You just need to return true/false depending 
// upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the driver code.

// Link-> https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    bool subArrayExists(int arr[], int n)
    {
        
        unordered_set<int>pt;
        int sum=0;
        for(int i=0;i<n;i++)
    {
            sum=sum+arr[i];
            if(sum==0||pt.find(sum)!=pt.end())
            {
                return true;
            }
            pt.insert(sum);
    }
        return false;
    }
};