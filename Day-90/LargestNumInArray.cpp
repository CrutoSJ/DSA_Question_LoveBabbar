// #Question:-

/*  Given an array of strings arr[] of length n representing non-negative integers, arrange them in a manner, such that, after concatanating them in order, 
    it results in the largest possible number. Since the result may be very large, return it as a string.*/

// Link -> https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
private: 
    static bool cmp(string a,string b)

    {

        if(a+b > b+a)return true;

        return false;

    }
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) {
	    // code here
	sort(arr.begin(),arr.end(),cmp);

    string ans = "";

    for(int i=0;i<arr.size();i++)

    {

        ans += (arr[i]);

    }

    return ans;
	}
};