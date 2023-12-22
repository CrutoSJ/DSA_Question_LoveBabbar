// #Question:-

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=0;
        
        for(int j=0; j<nums.size(); j++){
            if(nums[j]!=0){
                swap(nums[j], nums[s]);
                s++;
            }
        }
        
        
    }
};