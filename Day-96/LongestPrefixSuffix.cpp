// #Question:-

// https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1

// #SOlution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.size();
	    
	    for(int i = 1; i < n; ++i) 
	        if(s[0] == s[i]) if(s.substr(0, n - i) == s.substr(i)) return n - i;
	    
	    return 0;
	}
};