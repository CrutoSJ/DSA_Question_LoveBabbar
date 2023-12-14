// #Question:-

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

// #Soution:-

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        
        int mid = s + (e-s)/2;
        
        while(s<=e){
            
            if(nums[mid]==target){
                return mid;
            }
            
            else if(nums[mid]<target){
                s=mid+1;
            }
            
            else{
                e=mid-1;
            }
            
            mid = s+(e-s)/2;
        }
        
        return -1;
    }
};