// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

// Date-> 10/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int MOD = 10e8+7;
    
    long long add(long long a, long long b){
        return (a%MOD + b%MOD)%MOD;
    }
    
    long long mul(long long a, long long b){
        return (a%MOD * b%MOD)%MOD;
    }
    
    long long solve(int n, int k, vector<int> &dp){
        if(n==1){
            return k;
        }
        
        if(n==2){
            return add(k,mul(k,k-1));
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int ans = add(mul(solve(n-1, k, dp), k-1), mul(solve(n-2, k, dp), k-1));
        return dp[n] = ans;
    }
    long long countWays(int n, int k){
        vector<int> dp(n+1, -1);
        return solve(n, k, dp);
    }
};