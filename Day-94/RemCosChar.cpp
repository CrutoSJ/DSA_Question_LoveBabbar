// #Question:-

// LLink -> https://practice.geeksforgeeks.org/problems/consecutive-elements/0

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        for(int i=1; i<S.size(); i++){
            if(S[i-1]==S[i]){
                S.erase(i, 1);
                i--;
            }
        }
        
        return S;
    }
};