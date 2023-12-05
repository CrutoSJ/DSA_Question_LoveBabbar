#include<bits/stdc++.h>
using namespace std;

int nthTerm(int n){
    int a=0;
    int b=1;
    int sum =0;
    for(int i=1; i<n-1; i++){

        sum = a+b;
        a = b;
        b = sum;
    }
    return sum;
    
}

int main(){
    int n;
    cin >> n;

    cout << nthTerm(n);
}