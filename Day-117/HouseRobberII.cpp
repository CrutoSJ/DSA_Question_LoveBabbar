// #Question:-

// Link-> https://www.naukri.com/code360/problems/house-robber_839733

// Date-> 29/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

long long int solve(vector<int> &arr){

    int n = arr.size();
    long long int prev2 = 0;
    long long int prev1 = arr[0];

    for(int i=1; i<n; i++){
        long long int inc = prev2 + arr[i];
        long long int exc = prev1;

        long long int ans = max(inc, exc);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1; 
}

long long int houseRobber(vector<int>& arr){
    int n = arr.size();
    if (n == 1) return arr[0];

    vector<int> inc, exc;

    for(int i=0; i<n; i++){
        if(i != 0){
            exc.push_back(arr[i]);
        }
        if(i != (n-1)){
            inc.push_back(arr[i]);
        }
    }

    long long int ans = max(solve(inc), solve(exc));
    return ans;
}