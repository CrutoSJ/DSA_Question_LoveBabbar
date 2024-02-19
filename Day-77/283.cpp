// #Question:-

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        
        if(j==-1) return ;
        
        for(int i = j+1; i<nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
        return ;
    }
};