// #Question:-

// #Link-> https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> unionSet;
        for (int i = 0; i < n; i++)
            unionSet.insert(a[i]);
        for (int i = 0; i < m; i++)
            unionSet.insert(b[i]);
        return unionSet.size();
    }
};