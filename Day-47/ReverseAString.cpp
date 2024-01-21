// #Question:-

// You are given a string s. You need to reverse the string.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string reverseWord(string str)
    {
        // Your code goes here
        int s = 0;
        int e = str.length()-1;
        
        while(s<=e){
            swap(str[s], str[e]);
            s++;
            e--;
        }
        
        return str;
    }
};
