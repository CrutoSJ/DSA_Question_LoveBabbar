// #Question:-

// https://www.codingninjas.com/studio/problems/reverse-the-array_1262298

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m){

    int s=m+1;
    int e=arr.size()-1;

    while(s<=e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }      	
}