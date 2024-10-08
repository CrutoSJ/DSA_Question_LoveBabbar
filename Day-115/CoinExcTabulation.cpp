// #Question:-

// Link-> https://leetcode.com/problems/coin-change/description/

// Date-> 17/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        int mini = INT_MAX;

        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);
                }
            }
        }

        if(dp[amount] != INT_MAX){
            return dp[amount];
        }
        return -1;
    }
};