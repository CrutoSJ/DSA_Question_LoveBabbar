// #Question:-

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
private:
    bool isSame(int count1[26], int count2[26]){
        for(int i=0; i<26; i++){
            if(count1[i] != count2[i]){
                return 0;
            }
        }
        
        return 1;
    }
    
    
public:
    bool checkInclusion(string s1, string s2) {
        
        int count1[26] = {0};
        
        for(int i=0; i<s1.length(); i++){
            char ch = s1[i];
            int index = ch - 'a';
            count1[index]++;
        }
        
        int count2[26] = {0};
        int WinSize = s1.length();
        
        int i=0;
        
        while(i<WinSize && i<s2.length() ){
            char ch = s2[i];
            int index = ch - 'a';
            count2[index]++;
            i++;
        }
        
        if(isSame(count1, count2)){
            return true;
        }
        
        while(i<s2.length()){
            char newCh = s2[i];
            int index = newCh - 'a';
            count2[index]++;
            
            char oldch = s2[i-WinSize];
            index = oldch - 'a';
            count2[index]--;
            
            i++;
            
            if(isSame(count1, count2)){
                return true;
            }
            
            
        }
        
        return 0;
    }
};