// #Question:-

// Link-> https://www.naukri.com/code360/problems/maximum-frequency-number_920319

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int>mp;
    int maxFreq = 0; 

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
        maxFreq = max(maxFreq, mp[arr[i]]);
    }

    for (int i = 0; i < n; i++) {
        if (mp[arr[i]] == maxFreq) {
            return arr[i];
        }
    }
    return 0;
}