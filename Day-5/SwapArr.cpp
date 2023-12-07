#include<bits/stdc++.h>
using namespace std;

//takes input in array
void ArrInput(int arr[], int n){

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

}

//sorts the array
void ArrSort(int arr[], int n){
    for(int i=0; i<n; i+=2){
        if(i+2<=n){
            swap(arr[i],arr[i+1]);
        }
    }
}

//prints array
void ArrPrint(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int size;
    cin >> size;

    int arr[1000];
    ArrInput(arr, size); //array input from user

    ArrSort(arr,size); // sort the array
    ArrPrint(arr,size); //print the array

}