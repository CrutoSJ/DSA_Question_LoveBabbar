// #Question:-

// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int> bloomDay, int mid, int m, int k){
        int count = 0;
        int sum = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
            }
            else{
                sum += (count/k);
                count = 0;
            }
        }
        sum += (count/k);
        
        if(sum>=m){
            return true;
        }
        else{
            return false;
        }
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int total = m*1LL * k*1LL;
        
        if(total > bloomDay.size()){
            return -1;
        }
        
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isPossible(bloomDay, mid, m, k)){
                e = mid-1;
            }
            
            else {
                s = mid+1;
            }
        }
        
        return s;
    }
};