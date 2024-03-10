// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(), a.end());

        long long minDiff = LLONG_MAX;

        // Finding the minimum difference by comparing consecutive elements
        for (long long i = 0; i + m - 1 < n; i++) {
            long long diff = a[i + m - 1] - a[i];
            minDiff = min(minDiff, diff);
        }

        return minDiff;
    
    }   
};