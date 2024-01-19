// #Question:-

// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void mergeArr(vector<int> &nums, int s, int e){
    
    int mid = s + (e-s)/2;
    
    int size1 = mid - s + 1;
    int size2 = e - mid;
    
    int *arr1 = new int[size1];
    int *arr2 = new int[size2];
    
    int mainArrIndex = s;
    
    for(int i=0; i<size1; i++){
        arr1[i] = nums[mainArrIndex++];
    }
    
    for(int i=0; i<size2; i++){
        arr2[i] = nums[mainArrIndex++];
    }
    
    int index1=0;
    int index2=0;
    mainArrIndex = s;
    
    while(index1 < size1 && index2 < size2){
        if(arr1[index1] < arr2[index2]){
            nums[mainArrIndex++] = arr1[index1++];
        }
        
        else{
            nums[mainArrIndex++] = arr2[index2++];
        }
    }
    
    while(index1 < size1){
        nums[mainArrIndex++] = arr1[index1++];
    }
    
    while(index2 < size2){
        nums[mainArrIndex++] = arr2[index2++];
    }
    
    delete []arr1;
    delete []arr2;
    
}

void sortArr(vector<int> &nums, int s, int e){
    
    if(s>=e){
        return ;
    }
    
    int mid = s + (e-s)/2;
    
    sortArr(nums, s, mid); // for sorting the left part...
        
    sortArr(nums, mid+1, e); // for sorting the right part...
        
    mergeArr(nums, s, e);
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        sortArr(nums, 0, n);
        
        return nums;
    }
    
};