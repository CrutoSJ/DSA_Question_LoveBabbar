// #Question:-

// https://www.codingninjas.com/studio/problems/sort-0-1-2_631055

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n)
{
    int lo=0;
    int mid=0;
    int hi=n-1;
    while(mid<=hi){
    switch(arr[mid]){
        case 0:
            swap(arr[mid], arr[lo]);
            mid++;
            lo++;
            break;

        case 1:
            mid++;
            break;

        case 2:
            swap(arr[mid], arr[hi]);
            hi--;
            break;
        }
    }
}