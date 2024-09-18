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
    
    int countWays(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1]+dp[i-2])%MOD;
        }
        
        return dp[n]%MOD;
    }
};