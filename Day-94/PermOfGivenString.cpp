// #Question:-

// Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> result;
            sort(S.begin(), S.end());

            do
            {
                result.push_back(S);
            } while (next_permutation(S.begin(), S.end()));

            return result;
		    }
};