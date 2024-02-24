// #Question:-

// Take the principal amount, rate of interest, and the time period as input and calculate the Simple Interest.

// Note: Return answer as Floor integer value.

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

int main() {

    int principal;
    double rate;
    int time;

    cin>>principal>>rate>>time;

    int simpleInterest=principal*rate*time/100;

    cout<<simpleInterest<<endl;
    return 0;
}