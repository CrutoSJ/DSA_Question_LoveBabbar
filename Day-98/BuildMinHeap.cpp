// #Question:-

// Link->  https://www.naukri.com/code360/problems/build-min-heap_1171167

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int size, int i){
        //step 1:-
        int smallest = i;
        int left  = 2*i + 1;
        int right = 2*i + 2;

        if(left<size && arr[smallest] > arr[left]){
            smallest = left;
        }
        if(right<size && arr[smallest] > arr[right]){
            smallest = right;
        }

        if(smallest != i){
            swap(arr[smallest], arr[i]);
            heapify(arr, size, smallest);
        }
        
        return ;
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int s = arr.size();
    for(int i=s/2; i>=0; i--){
        heapify(arr, s, i);
    }

    return arr;
}
