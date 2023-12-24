// #Question:-

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0;
        int e=s.size()-1;
        
        while(start<=e){
            swap(s[start], s[e]);
            start++;
            e--;
        }
        
    }
};