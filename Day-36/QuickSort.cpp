// #Question:-

// https://www.codingninjas.com/studio/problems/quick-sort_983625

// #Solution:-

#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &arr, int s, int e){

    int pivotelement = arr[s];

    int cnt=0;

    for(int i=s+1; i<=e; i++){
        if(arr[i]<pivotelement){
            cnt++;
        }
    }

    int pindex = s + cnt;

    swap(arr[pindex], arr[s]);

    int i=s, j=e;

    while(i<pindex && j > pindex ){
        while(arr[i]<pivotelement){
            i++;
        }

        while(arr[j]>pivotelement){
            j--;
        }

        if(i<pindex && j > pindex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pindex;

}

void sortArr(vector<int>& arr, int s, int e){

    if(s>=e){
        return ;
    }

    int p = pivotIndex(arr, s, e);

    //sort left part.....
    sortArr(arr, s, p-1);

    //sort the right part....
    sortArr(arr, p+1, e);
}

vector<int> quickSort(vector<int> arr)
{
    int n = arr.size()-1;
    sortArr(arr,0,n);

    return arr;
}
