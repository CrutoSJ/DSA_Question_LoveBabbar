// #Question:-

// Given an array arr[ ] of N positive integers, the task is to find the greatest element on the left of every element in the array which is strictly smaller than 
// itself, if this element does not exist for an index print "-1".

// Link -> https://www.geeksforgeeks.org/problems/smaller-on-left20360700/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n)
{
    vector<int>ans(n,-1);
    set<int>temp;
    temp.insert(arr[0]);

    for(int i=1;i<n;i++)
    {
        vector<int>temp1(temp.begin(),temp.end());
        int index=lower_bound(temp1.begin(),temp1.end(),arr[i])-temp1.begin();
        if(index-1>=0)
        ans[i]=temp1[index-1];
        
        temp.insert(arr[i]);
    }
    return ans ;
}