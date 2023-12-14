// #Question:-

// https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int FirstOcc(vector<int>& arr, int n, int key){
    int s=0;
    int e=n-1;

    int mid = s + (e-s)/2;

    int ans = -1;
    while(s<=e){
        if(arr[mid]==key){
            ans = mid;
            e = mid-1;
        }

        if(arr[mid]<key){
            s=mid+1;
        }

        if(arr[mid]>key){
            e=mid-1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

int LastOcc(vector<int>& arr, int n, int key){
    int s=0;
    int e=n-1;

    int mid = s + (e-s)/2;

    int ans = -1;
    while(s<=e){
        if(arr[mid]==key){
            ans = mid;
            s = mid+1;
        }

        if(arr[mid]<key){
            s=mid+1;
        }

        if(arr[mid]>key){
            e=mid-1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> p;
    p.first = FirstOcc(arr, n, k);
    p.second = LastOcc(arr, n, k);

    return p;
}
