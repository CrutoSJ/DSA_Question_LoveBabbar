// #Question:-

// https://www.codingninjas.com/studio/problems/subsequences-of-string_985087

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

void solve(string str, vector<string>& ans, int index, string output){
	if(index>=str.length()){
		if(output.length()>0){
			ans.push_back(output);
		}
		return ;
	}

	//exclude it
	solve(str, ans, index+1, output);

	//include it
	char ch = str[index];
	output.push_back(ch);
	solve(str, ans, index+1, output);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
	string output = "";
	int index = 0;
	solve(str, ans, index, output);
	return ans;
	
}
