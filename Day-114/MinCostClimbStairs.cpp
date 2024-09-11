// #Question:-

// Leetcode -> 746

// Link->   https://leetcode.com/problems/min-cost-climbing-stairs/description/ 

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s = cost.size();
        int prev1 = cost[0];
        int prev2 = cost[1];

        for(int i=2; i<s; i++){
            int curr = min(prev1, prev2) + cost[i];
            prev1=prev2;
            prev2=curr;
        }
        return min(prev2, prev1);
    }
};