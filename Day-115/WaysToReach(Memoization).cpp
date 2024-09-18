// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int MOD = 10e8+7;
    int solve(int n, vector<int> &dp){
        if(n==0){
            return 1;
        }
        
        if(n<0){
            return 0;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        return dp[n] = (solve(n-1, dp) + solve(n-2, dp))%MOD;
        
    }
    int countWays(int n)
    {
        vector<int> dp(n+1, -1);
        int ans = solve(n, dp);
        return ans%MOD;
    }
};