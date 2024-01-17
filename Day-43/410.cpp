// #Question:-

// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& nums, int mid, int k){
        int parts = 1;
        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] + sum <= mid){
                sum += nums[i];
            }
            else{
                sum = nums[i];
                parts++;
            }
        }
        
        if(parts <= k){
            return true;
        }
        else{
            return false;
        }
    }    
    
    int solve(vector<int>&nums, int k){
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(isPossible(nums, mid, k)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    
public:
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()){
            return -1;
        }
        if(k==nums.size()){
            return *max_element(nums.begin(), nums.end());
        }
        return solve(nums, k);
    }
};