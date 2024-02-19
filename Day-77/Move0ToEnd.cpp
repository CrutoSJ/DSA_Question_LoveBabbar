// #Question:-

// Given an array 'arr' of 'n' non-negative integers, your task is to move all the zeros to the end of the array while keeping the non-zero elements at the start of the array in their original order. Return the modified array.

// Link-> https://www.codingninjas.com/studio/problems/ninja-and-the-zero-s_6581958

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            j=i;
            break;
        }
    }

    if(j==-1) return a;

    for(int i=j+1; i<n; i++){
        if(a[i] != 0){
            swap(a[i],a[j]);
            j++;
        }
    }
    return a;

}
