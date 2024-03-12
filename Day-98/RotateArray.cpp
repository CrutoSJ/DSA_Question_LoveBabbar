// #Question:-

// https://www.codingninjas.com/studio/problems/rotate-array_1230543

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    while(k){
        for(int i=1; i<arr.size(); i++){
            int element = arr[(i-1)%arr.size()];
            arr[(i-1)%arr.size()]=arr[i];
            arr[i]=element;
        }
        k--;
    }
    return arr;
}
