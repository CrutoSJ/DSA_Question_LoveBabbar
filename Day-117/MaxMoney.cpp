// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/maximum-money2855/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximizeMoney(int N , int K) {
        int ans = N%2 != 0 ? N/2 + 1 : N/2;
        return ans*K;
    }
};