// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minJumps(int arr[], int n){
    int maxi=0;
    int maxrange=0;
    int jump=0;
    if(n==1){
        return 0;
    }
    if(arr[0]==0){
        return -1;
    }
    for(int i=0;i<n;i++){
        maxi=max(maxi,i+arr[i]);
        if(maxrange==i){
            maxrange=maxi;
            jump++;
            if(maxrange>=n-1){
                return jump;
            }
        }
    }
    return -1;
    }
};