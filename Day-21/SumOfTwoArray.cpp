// #Question:-

// https://www.codingninjas.com/studio/problems/sum-of-two-arrays_893186

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> ans){
	int s=0;
	int e=ans.size()-1;

	while(s<=e){
		swap(ans[s++], ans[e--]);
	}

	return ans;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
	int i =n-1;
	int j =m-1;

	int carry=0;

	while(i>=0 && j>=0){
		int sum = a[i--]+b[j--]+carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
	}

	while(i>=0){
		int sum = a[i--]+carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
	}
	while(j>=0){
		int sum = b[j--]+carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
	}

	while(carry!=0){
		int sum = carry;
		carry = sum/10;
		sum = sum%10;
		ans.push_back(sum);
	}

	return reverse(ans);

}