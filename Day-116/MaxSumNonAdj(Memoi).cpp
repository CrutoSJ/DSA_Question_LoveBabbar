// #Question:-

// Link-> https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261

// Date-> 20/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int idx, vector<int> &dp){
    if(idx==nums.size()-1){
        return nums[idx];
    }

    if(idx>=nums.size()){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int sum = max((solve(nums, idx+2, dp) + nums[idx]), solve(nums, idx+1, dp));
    return dp[idx] = sum; 
}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1, -1);
    int ans = solve(nums, 0, dp);
    return ans;
}