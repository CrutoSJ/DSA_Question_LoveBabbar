//#Question:-

//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

//#Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, long long n) {
        n = static_cast<long long> (n);
        if(n==0) return 1;
        if(n<0) return 1/myPow(x, -n);
        if(n%2){
            return x*myPow(x*x, n/2);
        }

        return myPow(x*x, n/2);
    }
};

