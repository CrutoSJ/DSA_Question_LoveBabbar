// #Question:-

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum = sum^nums[i];
        }
        
        return sum;
        
    }
};