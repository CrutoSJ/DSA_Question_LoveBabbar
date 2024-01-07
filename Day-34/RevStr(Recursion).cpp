// #Question:-

// https://www.codingninjas.com/studio/problems/reverse-the-string_799927

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

void revString(string& str, int i){
	int n = str.length();
	if(i>n-i-1){
		return ;
	}

	swap(str[i], str[n-i-1]);

	revString(str, i+1);
}

string reverseString(string str)
{
	revString(str, 0);
	return str;
}