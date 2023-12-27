// #Question:-

// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string unique="";
        
        int index=0;
        
        while(index<s.length()){
            if(unique.length()>0 && unique[unique.length()-1]==s[index]){
                unique.pop_back();
            }
            else{
                unique.push_back(s[index]);
            }
            index++;
        }
        
        return unique;
    }
};