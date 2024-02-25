// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	string removeDuplicates(string str) {
	    string ans = "";
        unordered_set<char> seen;

        for (char c : str) {
            if (seen.find(c) == seen.end()) {
                ans.push_back(c);
                seen.insert(c);
            }
        }

        return ans;
	}
};