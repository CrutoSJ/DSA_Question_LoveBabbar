// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1

// Date-> 11/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MOD = 10e8+7;
    
    long int solve(int n, vector<int> &dp){
        if(n==1){
            return 0;
        }
        
        if(n==2){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        long int ans = ((n-1) * (solve(n-1, dp)%MOD + solve(n-2, dp)%MOD))%MOD;
        return dp[n] = ans;
    }
    
    long int disarrange(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};