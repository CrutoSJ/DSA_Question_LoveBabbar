// #Question:-

// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int val=k-arr[i];
            if(mp[val]){
                ans=ans+mp[val];
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};
