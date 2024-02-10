// #Question:-

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == a){
                a += 1;
            }
            else{
                return a;
            }
        }
        return a;
    }
};