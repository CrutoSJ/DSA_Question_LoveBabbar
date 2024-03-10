// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    int n = nums.size(); 
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];

        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        int rem = sum - k;

        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;

}