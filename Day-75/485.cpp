// #Question:-

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> ans;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                count++;
            }
            else if(nums[i] != 1){
                ans.push_back(count);
                count = 0;
            }
        }
        
        ans.push_back(count);
        
        int times = *max_element(ans.begin(),ans.end());
        return times;
    }
};