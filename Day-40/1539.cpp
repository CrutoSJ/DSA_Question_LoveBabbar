// #Question:-

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int missing = arr[mid] - (mid + 1);
            if(missing<k){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return s + k;
    }
};