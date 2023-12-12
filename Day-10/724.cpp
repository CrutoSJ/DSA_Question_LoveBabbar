// #Question:-

// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum=0, rightSum=0;
        for(int i=1; i<nums.size(); i++){
            rightSum += nums[i];
        }
        for(int j = 0; j<nums.size(); j++){
            if(j!=0){
                leftSum += nums[j-1];
            }
            if(j!=0){
                rightSum -= nums[j];
            }
            if(leftSum == rightSum){
                return j;
            }
        }
        return -1;
    }
};