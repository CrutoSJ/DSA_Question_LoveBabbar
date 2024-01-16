// #Question:-

// https://www.codingninjas.com/studio/problems/rose-garden_2248080

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int k, int m, int mid){
	int count = 0;
	int sum = 0;

	for(int i=0; i<arr.size(); i++){
		if(arr[i]<=mid){
			count++;
		}
		else{
			sum += count/k;
			count = 0;
		}
	}
	sum += count/k;

	if(sum>=m){
		return true;
	}
	else{
		return false;
	}
}

int roseGarden(vector<int> arr, int k, int m)
{
	long long int value = k*1LL * m*1LL;
	if(value>arr.size()){
		return -1;
	}

	int s = *min_element(arr.begin(), arr.end());
	int e = *max_element(arr.begin(), arr.end());

	while(s<=e){
		int mid = s + (e-s)/2;

		if(isPossible(arr, k, m, mid)){
			e = mid-1;
		}

		else{
			s = mid+1;
		}
	}
	return s;
}