// #Question:-

// Link-> https://www.naukri.com/code360/problems/minimum-elements_3843091

// #Solution

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int x, vector<int> &dp){
    if(x==0){
        return 0;
    }

    if(x<0){
        return INT_MAX;
    }

    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;

    for(int i=0; i<num.size(); i++){
        int ans = solve(num, x-num[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }

    return dp[x] = mini;
} 
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, -1);
    int ans = solve(num, x, dp);
    if(ans != INT_MAX){
        return ans;
    }
    return -1;
}