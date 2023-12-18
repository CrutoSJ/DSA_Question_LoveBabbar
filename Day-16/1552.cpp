// #Question:-

// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& position, int m, int mid, int n){
    int ball = 1;
    int lastPos = 0;
    
    
    for(int i=0; i<n; i++){
        if (position[i] - position[lastPos] >= mid){
            ball++;
            
            if(ball == m){
                return true;
            }
            
            lastPos = i;
        }
    }
    
    return false;
    
}

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s=0;
        int n = position.size();
        
        int e = *max_element(position.begin(), position.end());
        
        int mid = s + (e-s)/2;
        int ans=-1;
        
        while(s<=e){
            if(isPossible(position, m, mid, n)){
                ans =mid;
                s=mid+1;
            }
            
            else{
                e=mid-1;
            }
            
            mid = s + (e-s)/2;
            
        }
        
        return ans;
    }
};