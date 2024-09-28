// #Question:-

// Link-> https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261

// Date-> 28/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i=2; i<n; i++){
        int inc = dp[i-2] + nums[i];
        int exc = dp[i-1];
        dp[i] = max(inc, exc);
    }

    return dp[n-1];
}