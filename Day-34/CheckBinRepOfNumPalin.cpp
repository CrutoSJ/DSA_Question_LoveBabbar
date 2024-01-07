// #Question:-

// https://www.codingninjas.com/studio/problems/check-palindrome_920555

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

bool checkPalindrome(vector<int>& ans, int s, int e){

	if(ans[s]!=ans[e]){
		return false;
	}

	if(s>e){
		return true;
	}

	return checkPalindrome(ans, s+1, e-1);


}

bool checkPalindrome(long long N)
{
	vector<int>ans;
	while(N!=0){
		if(N&1){
			ans.push_back(1);
		}
		else{
			ans.push_back(0);
		}
		N=N>>1;
	}
	int n = ans.size()-1;
	return checkPalindrome(ans, 0, n);
}