// #Question:-

// Given a string str of lowercase alphabets. The task is to find the maximum occurring character in the string str. If more than one character occurs the
// maximum number of time then print the lexicographically smaller character.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            
            int index = 0;
            
            index = ch - 'a';
            arr[index]++;
        }
        
        int maxi=-1, ans =0;
        for(int i=0; i<26; i++){
            if(maxi<arr[i]){
                ans = i;
                maxi = arr[i];
            }
        }
        
        return ans + 'a';
    }

};