// #Question:-

// https://www.codingninjas.com/studio/problems/cooking-ninjas_1164174

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &rank, int m, int n, int mid){
    int cooktime=0;
    int dish=0;
    for(int i=0; i<n; i++){
        cooktime = rank[i];
        int j =2;

        while(cooktime<=mid){
            dish++;
            cooktime += (rank[i]*j);
            j++;
        }

        if(dish >= m){
            return true;
        }
    }
    return false;
}

#include <bits/stdc++.h> 
int minCookTime(vector<int> &rank, int m)
{
    int s = 0;
    int e=0;
    for(int i=0; i<m; i++){
        e += (i+1)*rank[0];
    }

    int mid = s + (e-s)/2;
    int ans = -1;
    int n = rank.size();

    while(s<=e){

        if(isPossible(rank, m, n, mid)){
            ans = mid;
            e = mid-1;
        }

        else{
            s = mid+1;
        }

        mid = s + (e-s)/2;

    }

    return ans;


}
