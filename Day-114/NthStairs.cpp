// #Question:-

// Link-> https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int countDistinctWays(int nStairs) {

    if(nStairs==0 || nStairs==1){
        return 1;
    }

    int prev1 = 1;
    int prev2 = 1;

    for(int i=2; i<=nStairs; i++){
        int curr = (prev1+prev2)%mod;
        prev2=prev1;
        prev1=curr;
    }

    return prev1;
}