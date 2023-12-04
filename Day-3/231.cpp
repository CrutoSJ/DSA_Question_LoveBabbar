// #Question:-

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        
        int ans=1;
        
        for(int i=0; i<=30; i++){
            
            if(ans==n){
                return true;
            }
            
            if(ans<INT_MAX/2){
                ans = ans*2;
            }
        }
    return false;
        
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Solution obj;
        bool result = obj.isPowerOfTwo(n);

        if (result) {
            cout << "True\n";
        } else {
            cout << "False\n";
        }
    }

    return 0;
}