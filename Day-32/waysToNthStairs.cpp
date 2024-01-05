// #Question:-

// https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }

    return countDistinctWays(nStairs-1) + countDistinctWays(nStairs-2);
}