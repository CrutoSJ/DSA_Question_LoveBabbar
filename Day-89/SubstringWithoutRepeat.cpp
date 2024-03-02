// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/longest-substring-without-repeating-characters_630418

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

int uniqueSubstrings(string input)
{
    int n = input.length();
        int maxlen = 0;
        vector<int> charindex(128, -1);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charindex[input[right]] >= left) {
                left = charindex[input[right]] + 1;
            }
            charindex[input[right]] = right;
            maxlen = max(maxlen, right - left + 1);
        }
        
        return maxlen;

}