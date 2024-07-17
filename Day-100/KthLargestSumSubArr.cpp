// #Question:-

// Link-> https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	int size = arr.size();

	priority_queue<int, vector<int>, greater<int>>minHeap;

	for(int i=0; i<size; i++){
		int sum = 0;
		for(int j=i; j<size; j++){
			sum += arr[j];

			if(minHeap.size()<k){
				minHeap.push(sum);
			}
			
			else{
				if(minHeap.top() < sum){
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}
	return minHeap.top();


}