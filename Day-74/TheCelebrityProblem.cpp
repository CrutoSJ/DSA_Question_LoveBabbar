// #Question:-

// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>s;
        for(int i=0; i<n; i++){
            s.push(i);
        }
        
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        int ans = s.top();
        
        int zeroCount = 0;
        for(int i=0; i<n; i++){
            if(M[ans][i] == 0) zeroCount++;
        }
        
        
        if(zeroCount != n) return -1;
        
        
        int oneCount = 0;
        for(int i=0; i<n; i++){
            if(M[i][ans] == 1) oneCount++;
        }
        
        
        if(oneCount != n-1) return -1;
        
        return ans;
        
    }
};