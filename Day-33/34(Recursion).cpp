// #Questtion:-

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& nums, int s, int e, int key, int ans1){
    
    if(s>e){
        return ans1;
    } 
    
    int mid = s + (e-s)/2;
    
    if(nums[mid]==key){
        ans1 = mid;
        return firstOcc(nums, s, mid-1, key, ans1);
        
    }
    
    else if(nums[mid]<key){
        return firstOcc(nums, mid+1, e, key, ans1);
    }
    else{
        return firstOcc(nums, s, mid-1, key, ans1);
    }
    
    return ans1;
}

int lastOcc(vector<int>& nums, int s, int e, int key, int ans2 ){
    if(s>e){
        return ans2;
    } 
    
    int mid = s + (e-s)/2;
    
    if(nums[mid]==key){
        ans2 = mid;
        return lastOcc(nums, mid+1, e, key, ans2);

    }
    
    if(nums[mid]<key){
        return lastOcc(nums, mid+1, e, key, ans2);
    }
    else{
        return lastOcc(nums, s, mid-1, key, ans2);
    }
    
    return ans2;
    
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        ans.push_back(firstOcc(nums, 0, nums.size()-1, target, -1));
        ans.push_back(lastOcc(nums, 0, nums.size()-1, target, -1));
        
        return ans;
        
    }
};