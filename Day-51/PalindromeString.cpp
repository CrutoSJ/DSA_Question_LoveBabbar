// #Question:-

// Given a string S, check if it is palindrome or not.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	

int isPalindrome(string S){

	int s=0;
	int e=S.length()-1;
	
	while(s<=e){
	    if(S[s]==S[e]){
	    s++;
	    e--;
	}

	else if(S[s] != S[e]){
	        return 0;
	    }
	}
	    
	return 1;
    
	}

};