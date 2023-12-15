// #Question:-

// https://www.codingninjas.com/studio/problems/allocate-books_1090540

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid){

    if(n<m){
        return false;
    }
    int student=1;
    int Pagesum=0;

    for(int i=0; i<n; i++){
        if(Pagesum + arr[i] <= mid){
            Pagesum += arr[i];
        }
        else{
            student++;

            if(student > m || arr[i]>mid){
                return false;
            }
            
            Pagesum = arr[i];
        }
    }

    return true;

}

int findPages(vector<int>& arr, int n, int m) {
    int s=0;
    int sum=0;
    int ans=-1;

    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int e = sum;

    int mid = s + (e-s)/2;

    while(s<=e){
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid-1;
        }

        else{
            s = mid+1;
        }

        mid = s + (e-s)/2;
    }

    return ans;
}