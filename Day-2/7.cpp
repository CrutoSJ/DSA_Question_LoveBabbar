// #Question:-

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int ans=0;

        while(x!=0){
            int digit = x%10;
            if((ans<INT_MIN/10)||(ans>INT_MAX/10)){
                cout << 0;
            }
            ans = (ans*10) + digit;
            x = x/10;

        }
        cout << ans;
    }
}