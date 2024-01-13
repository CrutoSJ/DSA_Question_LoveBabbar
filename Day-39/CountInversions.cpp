// #Question:-

// https://www.codingninjas.com/studio/problems/count-inversions_615

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

long long mergeArr(long long *arr, int s, int e){
    int mid = s + (e-s)/2;
    long long count=0;

    int size1 = mid - s + 1;
    int size2 = e - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    int mainIdx = s;

    for(int i=0; i<size1; i++){
        arr1[i] = arr[mainIdx++];
    }

    for(int i=0; i<size2; i++){
        arr2[i] = arr[mainIdx++];
    }

    mainIdx = s;
    int Index1=0;
    int Index2=0;

    while(Index1<size1 && Index2<size2){
        if(arr1[Index1] < arr2[Index2]){
            arr[mainIdx++] = arr1[Index1++];
        }

        else{
            arr[mainIdx++] = arr2[Index2++];
            count += size1 - Index1;
        }
    }

    while(Index1<size1){
        arr[mainIdx++] = arr1[Index1++];
    }

    while(Index2<size2){
        arr[mainIdx++] = arr2[Index2++];
    }

    delete []arr1;
    delete []arr2;

    return count;

}

long long sortArr(long long *arr, int s, int e){

    long long count = 0;

    if(s>=e){
        return count;
    }

    int mid = s + (e-s)/2;

    count += sortArr(arr,s,mid);
    count += sortArr(arr,mid+1,e);

    count += mergeArr(arr,s,e);

    return count;
}

long long getInversions(long long *arr, int n){
    return sortArr(arr, 0, n-1);
}