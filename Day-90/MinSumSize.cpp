// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/find-minimum-sum-subarray-of-given-size_873368

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

int minSubarraySum(int arr[], int n, int k) {

    if (n < k) {
        // If array length is less than k, it's not possible to have a subarray of length k.
        return -1; // Or any appropriate error code to indicate invalid input.
    }

    int ans = INT_MAX;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    ans = min(sum, ans);

    for (int i = k; i < n; i++) {
        // Subtract the visited element and add the new elements
        sum = sum - arr[i - k] + arr[i];
        ans = min(ans, sum);
    }

    return ans;
}
