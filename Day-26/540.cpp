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
        
        int n=nums.size();
	    if(n==1){return nums[0];}
	    if(nums[0]!=nums[1]){ return nums[0];}
	    if(nums[n-1]!=nums[n-2]){return nums[n-1];}

	    int s = 1;
	    int e = n-2;
        
        int mid = s + (e-s)/2;
        
        while(s<=e){
            
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            
            if(mid%2==0 && nums[mid-1]==nums[mid] || mid%2==1 && nums[mid]== nums[mid+1]){
                e = mid-1;
            }
            
            else{
                s = mid + 1;
            }
            
            mid = s + (e-s)/2;
            
        }
        
        return 0;
        
    }
};