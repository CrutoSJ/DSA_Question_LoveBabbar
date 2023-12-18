// #Question:-

// A conveyor belt has packages that must be shipped from one port to another within days days.

// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int MaxCap(vector<int>& weights, int mid){
    
    int count=1;
    int LoadSum=0;
    
    for(int i=0; i<weights.size(); i++){
        if(weights[i] + LoadSum > mid){
            count += 1;
            LoadSum = weights[i];
        }
        
        else{
            LoadSum += weights[i];
        }
    }
    
    return count;
}

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s= *max_element(weights.begin(), weights.end());
        int e= accumulate(weights.begin(), weights.end(), 0);    
        while(s<=e){
            int mid = s + (e-s)/2;
            
            int numberofDays = MaxCap(weights, mid);
            if(numberofDays <= days){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};