// #Question:-

// #Link-> https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        
        long long maxCount = INT_MIN;
        long long maxSum = 0;
        
        for(int i=0; i<n; i++){
            maxSum += arr[i];
            
            if(maxCount<maxSum){
                maxCount=maxSum;
            }
            
            if(maxSum<0){
                maxSum=0;
            }
        }
        
        return maxCount;
        
    }
};