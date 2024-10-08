// #Question :-

// Link-> https://www.naukri.com/code360/problems/count-derangements_873861

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int MOD = 10e8+7;

long long int solve(int n){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    long long int ans = ((n-1) * ((solve(n-1))%MOD + (solve(n-2))%MOD)%MOD)%MOD;
    return ans;
}

long long int solveMem(int n, vector<long long int> &dp){
    if(n == 1){
        return 0;
    }

    if(n == 2){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    long long int ans = ((n-1) * ((solveMem(n-1, dp))%MOD + (solveMem(n-2, dp))%MOD)%MOD)%MOD;
    return dp[n] = ans;
}

long long int solveTabu(int n){
    vector<long long int> dp(n+1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        long long int func1 = dp[i-1]%MOD;
        long long int func2 = dp[i-2]%MOD;
        // long long int sum   = (func1 + func2) % MOD;
        long long int ans   = ((i-1)*(func1 + func2) % MOD)%MOD;
        dp[i] = ans;
    }

    return dp[n];
}

long long int countDerangements(int n) {
    // 1st - Recurssion :-
    
    /*
    return solve(n);
    */

    //2nd - Recurssion + Memoization:-
    
    /*
    vector<long long int> dp(n+1, -1);
    return solveMem(n, dp);
    */

    //3rd - Tabulation :-

    /*
    return solveTabu(n);
    */

    //Space Optimized :-

    long long int prvs2 = 0;
    long long int prvs1 = 1;

    for(int i=3; i<=n; i++){
        long long int func1 = prvs1%MOD;
        long long int func2 = prvs2%MOD;
        long long int ans   = ((i-1)*(func1 + func2) % MOD)%MOD;
        prvs2 = prvs1;
        prvs1 = ans;
    }
    return prvs1;
}