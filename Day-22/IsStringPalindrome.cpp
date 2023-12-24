// #Question:-

// https://www.codingninjas.com/studio/problems/check-if-the-string-is-a-palindrome_1062633

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

//function which checks for any special characters:-
bool isValid(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' &&  ch <= '9')){
        return 1;
    }
    return 0;
}

//function which makes Not Case Sensitive:-
char toLower(char ch){
    if((ch >='a' && ch <= 'z') || (ch >='0' && ch<='9')){
        return ch;
    }

    else{
        ch = ch - 'A' + 'a';
        return ch;  
    }

}

//function which checks if it is palindrome or not:-
bool Ispalindrome(string a){
    int start = 0;
    int end = a.length()-1;

    while(start<=end){
        if(a[start]!=a[end]){
            return 0;
        }

        else{
            start++;
            end--;
        }

    }

    return 1;
}

bool checkPalindrome(string s)
{
    string temp = "";
    int n = s.size();

    for(int i=0; i<n; i++){
        if(isValid(s[i])){
            temp.push_back(s[i]);
        }
    }

    for(int i=0; i<temp.length();i++){
        temp[i] = toLower(temp[i]);
    }

    return Ispalindrome(temp);
    
}