// #Question:-

// https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149

// #Solution::-

#include <bits/stdc++.h> 
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;
	int first=0;
	int second=0;
	while(first< n && second <m){
		if(arr1[first]==arr2[second]){
			ans.push_back(arr1[first]);
			arr1[first]=-1;
			arr2[second]=-2;
			first++;
			second++;
		}
		if(arr1[first]<arr2[second]){
			first++;
		}
		if(arr1[first]>arr2[second]){
			second++;
		}
		
	}
	return ans;
}