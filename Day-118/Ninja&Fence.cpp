// #Question:-

// Link-> https://www.naukri.com/code360/problems/ninja-and-the-fence_3210208

// Date-> 08/10/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int MOD = 10e8+7;

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a, int b){
    return (a%MOD * 1LL * b%MOD)%MOD;
}

int solve(int n, int k){
    if(n==1){
        return k;
    }

    if(n==2){
        return add(k, mul(k,k-1));
    }

    int ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));

    return ans;
}

int solveMem(int n, int k, vector<int> &dp){
    if(n==1){
        return k;
    }

    if(n==2){
        return add(k, mul(k,k-1));
    }

    if(dp[n] != -1){
        return dp[n];
    }

    int ans = add(mul(solveMem(n-2, k, dp), k-1), mul(solveMem(n-1, k, dp), k-1));

    return dp[n] = ans;
}

int solveTab(int n, int k){
    vector<int> dp(n+1);
    dp[1] = k;
    dp[2] = add(k, mul(k,k-1));

    for(int i=3; i<=n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }

    return dp[n];
}

int numberOfWays(int n, int k) {

    // Recursion TC- exponential

    /*
    return solve(n, k);  -> recursion TC- exponential
    */


    // Rec + Memo:- TC- O(n) &&  Sc- O(n) + O(n) i.e dp arr & rec Stack

    /*
    vector<int> dp(n+1, -1);
    return solveMem(n,k,dp);

    */


    // Tabulation :-  TC- O(n) && SC- O(n); 

    /*
    return solveTab(n,k);
    */

    int prev1 = add(k, mul(k,k-1));
    int prev2 = k;

    for(int i=3; i<=n; i++){
        int ans = add(mul(prev1, k-1), mul(prev2, k-1));
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}