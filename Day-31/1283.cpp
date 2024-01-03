// #Question:-

// Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

// Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

// The test cases are generated so that there will be an answer.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
class Solution {
    
private: 
    bool isSmallest(vector<int>& nums, int mid, int threshold){
        int sum=0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            sum += ceil(static_cast<double>(nums[i]) / nums[mid]);
        }
        
        if(sum<=threshold){
            return true;
        }
        
        else{
            return false;
        }
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 0;
        int e = nums.size()-1;
        
        sort(nums.begin(), nums.end());
        int ans = -1;
        
        while(s<=e){
            
            int mid = s + (e-s)/2;
            
            if(isSmallest(nums, mid, threshold)){
                ans = nums[mid];
                e = mid-1;
            }
            
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
};