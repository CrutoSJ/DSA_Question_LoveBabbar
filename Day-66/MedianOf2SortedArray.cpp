// #Question:-

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int count = 0;
        int n = n1+n2;
        int index2 = n/2;
        int index1 = index2 - 1;
        int val1 = -1 , val2 = -1;
        int i = 0 , j = 0;
        
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                if(count == index1){
                    val1 = nums1[i];
                }
                if(count == index2){
                    val2 = nums1[i];
                }
                count++;
                i++;
            }
            else{
                if(count == index1){
                    val1 = nums2[j];
                }
                if(count == index2){
                    val2 = nums2[j];
                }
                count++;
                j++;
            }
        }
        
        while(i<n1){
            if(count == index1){
                    val1 = nums1[i];
                }
            if(count == index2){
                    val2 = nums1[i];
            }
            count++;
            i++;
        }
        
        while(j<n2){
            if(count == index1){
                    val1 = nums2[j];
                }
            if(count == index2){
                    val2 = nums2[j];
            }
            count++;
            j++;
        }
            
        if(n%2 == 1){
            return val2;
        }
        
        return (double)((double)(val1+val2)) / 2.0; 
        
    }
};