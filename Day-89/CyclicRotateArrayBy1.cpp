// #Question:-

// Given an array, rotate the array by one position in clock-wise direction.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    for(int i = n-1; i > 0; i--)
        swap(arr[i],arr[i-1]);
}