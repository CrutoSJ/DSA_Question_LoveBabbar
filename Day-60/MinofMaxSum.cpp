// #Question:-

// link -> https://www.codingninjas.com/studio/problems/largest-subarray-sum-minimized_7461751

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int>&a, int k){
    int sum = 0;
    int count = 1;

    for(int i=0; i<a.size(); i++){
        if(sum+a[i] <= mid){
            sum += a[i];
        }
        else{
            count++;
            sum = a[i];
        }
    }

    if(count<=k){
        return true;
    }

    else{
        return false;
    }
}

int largestSubarraySumMinimized(vector<int> a, int k) {
    int s = *max_element(a.begin(), a.end());
    int e = accumulate(a.begin(), a.end(), 0);


    while(s<=e){
        int mid = s + (e-s)/2;
        
        if(isPossible(mid,a,k)){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return s;
}