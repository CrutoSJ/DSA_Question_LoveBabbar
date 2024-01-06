// #Question:-

// https://www.codingninjas.com/studio/problems/binary-search_972

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int BinSearch(vector<int> &nums, int start, int end, int target){
    if(start>end){
        return -1;
    }

    int mid = start + (end-start)/2;

    if(nums[mid]==target){
        return mid;
    }

    if(nums[mid]<target){
        return BinSearch(nums, mid+1, end, target);
    }
    else{
        return BinSearch(nums, start, mid-1, target);
    }
}

int search(vector<int> &nums, int target) {
    BinSearch(nums, 0, nums.size()-1, target);

}