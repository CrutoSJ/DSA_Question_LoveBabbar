// #Question:-

// https://www.codingninjas.com/studio/problems/aggressive-cows_1082559

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid){
    int cow=1;
    int lastPos = stalls[0];
    for(int i=0; i<stalls.size(); i++){
        if(stalls[i] - lastPos >= mid){
            cow++;
            if (cow == k) {
            return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());

    int s = 0;
    int e = (*max_element(stalls.begin(), stalls.end()))-s;

    int mid = s + (e-s)/2;
    int ans = -1;

    while(s<=e){
        if(isPossible(stalls, k, mid)){
            ans = mid;
            s = mid+1;
        }

        else{
            e = mid-1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}