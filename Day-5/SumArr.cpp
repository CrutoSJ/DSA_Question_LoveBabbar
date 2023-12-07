#include<bits/stdc++.h>
using namespace std;

int ArrSum(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    return sum;
}

int main(){
    int size;
    cin >> size;

    int arr[1000];
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }

    int ans= ArrSum(arr,size);
    cout << "Arr sum: " << ans << endl;
}