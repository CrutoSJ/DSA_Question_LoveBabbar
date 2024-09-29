// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[], int n){
        
        int prev2 = 0;
        int prev1 = arr[0];
        
        for(int i=1; i<n; i++){
            int include = prev2 + arr[i];
            int exclude = prev1;
            
            int ans = max(include, exclude);
            prev2 = prev1;
            prev1 = ans;
        }
        
        return prev1;
    }
    
    
    int FindMaxSum(int arr[], int n)
    {
        if(n==1){
            return arr[0];
        }
        
        return solve(arr, n);
    }
};