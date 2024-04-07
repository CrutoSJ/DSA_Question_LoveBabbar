// #Question:-

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

// attempt - 2

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int i = 0;
        sort(arr.begin(),arr.end());
        vector<int> ans;
        while (i < arr.size()){
            int count = 1; //evry no. comes atleast once.
            for (int j = i+1; j< arr.size(); j++){
                if (arr[i] == arr[j])
                    count++;
            }
            ans.push_back(count);
            i = i + count; //skipping the same elements, jidhar start kiya+same nos. 
        }
        sort(ans.begin(),ans.end()); //so any same occurance come next to each other.
        for (int i = 0; i < ans.size() - 1; i++){
            if (ans[i] == ans [i+1])
                return false;
        }
        return true;
    }
};