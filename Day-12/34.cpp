// #Question:-

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& nums, int n, int key){
    int s=0;
    int e=n-1;
    
    int mid = s + (e-s)/2;
    int ans=-1;
    
    while(s<=e){
        if(nums[mid]==key){
            ans = mid;
            e=mid-1;
        }
        
        if(nums[mid]<key){
            s=mid+1;
        }
        
        if(nums[mid]>key){
            e=mid-1;
        }
        
        mid = s + (e-s)/2;
    }
    
    return ans;
}

int lastOcc(vector<int>& nums, int n, int key){
    int s=0;
    int e=n-1;
    
    int mid = s + (e-s)/2;
    int ans=-1;
    
    while(s<=e){
        if(nums[mid]==key){
            ans = mid;
            s=mid+1;
        }
        
        if(nums[mid]<key){
            s=mid+1;
        }
        
        if(nums[mid]>key){
            e=mid-1;
        }
        
        mid = s + (e-s)/2;
    }
    
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans;
        ans.push_back(firstOcc(nums, nums.size(), target));
        ans.push_back(lastOcc(nums, nums.size(), target));
        
        return ans;
        
    }
};