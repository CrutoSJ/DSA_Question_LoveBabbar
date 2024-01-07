// #Question:-

// https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int firstOCC(vector<int>& arr, int s, int e, int key, int ans1){
	if(s>e){
		return ans1;
	}

	int mid = s + (e-s)/2;

	if(arr[mid]==key){
		ans1 = mid;
		return firstOCC(arr, s, mid-1, key, ans1);
	}

	if(arr[mid]<key){
		return firstOCC(arr, mid+1, e, key, ans1);
	}

	else{
		return firstOCC(arr, s, mid-1, key, ans1);
	}

	return ans1;
}

int lastOCC(vector<int>& arr, int s, int e, int key, int ans2){
	if(s>e){
		return ans2;
	}

	int mid = s + (e-s)/2;

	if(arr[mid]==key){
		ans2 = mid;
		return lastOCC(arr, mid+1, e, key, ans2);
	}

	if(arr[mid]<key){
		return lastOCC(arr, mid+1, e, key, ans2);
	}

	else{
		return lastOCC(arr, s, mid-1, key, ans2);
	}

	return ans2;
}

int count(vector<int>& arr, int n, int x) {
	int first = firstOCC(arr, 0, n-1, x, -1);
	int last  = lastOCC(arr, 0, n-1, x, -1);

	if((first+last<=0)){
		return 0;
	}
	else{
		return ((last-first)+1);
	}
}
