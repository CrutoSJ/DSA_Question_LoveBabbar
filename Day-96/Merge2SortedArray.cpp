// #Question:-

// #Link-> https://www.codingninjas.com/studio/problems/sorted-array_6613259

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    map<int, int> mpp;

    int i;

    for (i = 0; i < a.size(); i++) {

        mpp.insert({a[i], 1});

    }

    for (i = 0; i < b.size(); i++) {

        mpp.insert({b[i], 1});

    }

    vector<int> v;

    for (auto &it : mpp) {

        v.push_back(it.first);

    }

    return v;

}