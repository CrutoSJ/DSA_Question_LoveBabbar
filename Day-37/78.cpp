// #Question:-

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int> nums, vector<vector<int>> & ans, vector<int> output, int index){
        if(index>= nums.size()){
            ans.push_back(output);
            return ;
        }
        
        //exclude the part
        solve(nums, ans, output, index+1);
        
        //include the part
        int element = nums[index];
        output.push_back(element);
        solve(nums, ans, output, index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, ans, output, index);
        return ans;
    }
};