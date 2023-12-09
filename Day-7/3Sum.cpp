// Problem Statement:-

// https://www.codingninjas.com/studio/problems/triplets-with-given-sum_893028

// Solution:-


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> ans;
    int left,right;
    bool found = false;
    sort(arr.begin(), arr.end());
    for(int i=0; i< n-2; i++){
        left = i+1;
        right=n-1;
        while(left<right){
            int current = arr[i]+arr[left]+arr[right];
            if(current==K){
                ans.push_back({arr[i], arr[left], arr[right]});
                found = true;
            }
            if(current<K){
                left++;
            }
            else{
                right--;
            }

        }
    }
    if(found){
            return ans;
        }
    // else{
    //     cout << "-";
    // }
    
}