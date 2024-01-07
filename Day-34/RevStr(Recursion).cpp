// #Question:-

// https://www.codingninjas.com/studio/problems/reverse-the-string_799927

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

void revString(string& str, int i, int j){
	if(i>j){
		return ;
	}
	swap(str[i], str[j]);
	revString(str, i+1, j-1);
}

string reverseString(string str)
{
	revString(str, 0, str.length()-1);
	return str;
}