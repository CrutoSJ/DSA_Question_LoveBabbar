// #Question:-

// https://www.codingninjas.com/studio/problems/selection-sort_981162

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    for(int i=0; i<n-1; i++){
        int MinIndex=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[MinIndex])
            MinIndex = j;
        }

        swap(arr[i], arr[MinIndex]);
    }
}