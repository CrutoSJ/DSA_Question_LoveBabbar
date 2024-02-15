// #Question:-

// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the form S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters.
// Calculate the minimum number of swaps necessary to make a string balanced.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int ans =0, n= S.size();
        int count=0;
        
        for(int i=0;i<n;i++)
        {
           if(S[i]=='[')
           count++;
           else
           {
               count--;
               if(count<0)
               ans-=count;
           }
        }
        return ans;
    }
};