// #Question:-

// https://www.codingninjas.com/studio/problems/merge-sort_920442

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void mergeArr(vector<int> &arr, int s, int e){

    int mid = s + (e-s)/2;

    int size1 = mid - s + 1;
    int size2 = e - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    int mainIndex = s;

    for(int i=0; i<size1; i++){
        arr1[i] = arr[mainIndex++];
    }
    

    for(int i=0; i<size2; i++){
        arr2[i] = arr[mainIndex++];
    }

    mainIndex = s;
    int index1 = 0;
    int index2 = 0;

    while( index1 < size1 && index2 < size2){
        if(arr1[index1] < arr2[index2]){
            arr[mainIndex++] = arr1[index1++];
        }

        else{
            arr[mainIndex++] = arr2[index2++];
        }
    }

    while(index1 < size1){
        arr[mainIndex++] = arr1[index1++];
    }

    while (index2 < size2) {
        arr[mainIndex++] = arr2[index2++];
    }
}

void sortArr(vector<int> &arr, int s, int e){

    if(s>=e){
        return ;
    }

    int mid = s + (e-s)/2;

    //left part sort....
    sortArr(arr, s, mid);

    //right part sort...
    sortArr(arr, mid+1, e);

    mergeArr(arr, s, e);

}

void mergeSort(vector < int > & arr, int n) {
    sortArr(arr, 0, n-1);
}
