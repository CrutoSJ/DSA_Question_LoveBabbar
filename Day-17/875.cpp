// #Question:-


// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& piles, int h, int mid) {
    long long int hour = 0;
    for (int i = 0; i < piles.size(); i++) {
        // Calculate hours needed to eat the current pile
        hour += (piles[i] + mid - 1) / mid;
    }

    return hour <= h;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (s <= e) {
            long long int mid = s + (e - s) / 2;

            if (isPossible(piles, h, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
