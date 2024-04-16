// #Question:-

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

//Attempt - 2

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& nums, int n){
    int s=0;
    int e=n;
    
    int mid = s + (e-s)/2;
    
    while(s<e){
        if(nums[mid]>=nums[0]){
            s=mid+1;
        }
        
        else{
            e = mid;
        }
        
        mid = s +(e-s)/2;
    }
    
    return s;
}

int BinSearch(vector<int>& nums, int s, int e, int key){
    int start=s;
    int end=e;
    
    int mid = start + (end-start)/2;
    
    while(start<=end){
        if(nums[mid]==key){
            return mid;
        }
        
        if(nums[mid]<key){
            start = mid+1;
        }
        
        else{
            end=mid-1;
        }
        
        mid = start + (end-start)/2;
    }
    
    return -1;
}


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        
        int pivotindex = findPivot(nums, n);
        
        
        if(target >= nums[pivotindex] && target  <= nums[n]){
            return BinSearch(nums, pivotindex, n, target);

        }
        else{
            return BinSearch(nums, 0, pivotindex-1, target);
        }
        
    }
};