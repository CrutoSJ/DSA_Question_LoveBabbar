// #Question:-

// https://www.codingninjas.com/studio/problems/ayush-and-ninja-test_1097574

// #Solution:-


#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> time, int n, int m,long long int mid){
	

	long long int days=1;
	long long int TotalStudy = 0;

	for(int i=0; i<m; i++){
		if(TotalStudy + time[i] <= mid){
			TotalStudy += time[i];
		}

		else{
			days++;
			if(days>n || time[i]>mid){
				return false;
			}

			TotalStudy = time[i];
		}
	}

	return true;


}

#include <bits/stdc++.h> 
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	if(n>m){ // condition to check if days is greater or not.
		return -1;
	}

	long long int s =0;
	long long int sum =0;

	for(long long int i=0; i<m; i++){
		sum += time[i];
	}

	long long int e = sum;

	long long int mid = s + (e-s)/2;
	long long int ans = -1;

	while(s<=e){
		if(isPossible(time, n, m, mid)){
			ans = mid;
			e = mid - 1;
		}

		else{
			s = mid+1;
		}
		
		mid = s + (e-s)/2;
	}

	return ans;
}