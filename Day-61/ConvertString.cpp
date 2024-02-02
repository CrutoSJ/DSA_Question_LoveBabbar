// #Question:-

// You are given a string 'STR'. You have to convert the first alphabet of each word in a string to UPPER CASE.

// For example:

// If the given string 'STR' = ”I am a student of the third year” so you have to transform this string to ”I Am A Student Of The Third Year"
// Note:

// 'STR' will contains only space and alphabets both uppercase and lowercase. The words will be separated by space.

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

string convertString(string str) 
{
	if(str.length()>0){
		for(int i=0; i<str.length(); i++){
			if(i == 0){
				str[i] = toupper(str[i]);
			}
			else if(str[i] == ' '){
				str[i+1] = toupper(str[i+1]);
			}
		}
	}
	return str;
}