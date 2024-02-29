// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int isSorted(int n, vector<int> a) {
    for (int i=0;i<n;i++){
        if(a[i]>=a[i-1]){
            i++;
        }
        
        else{
            return false;
        }
    }
    return true;
}