// #Question:-

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int fibRec(int n, vector<int>& dp){
        if(n==0 || n==1){
            return n;
        }
        if(dp[n]!= -1){
            return dp[n];
        }
        dp[n] = fibRec(n-1, dp) + fibRec(n-2, dp);
        return dp[n];
    }
    
    
    
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fibRec(n, dp);
    }
};