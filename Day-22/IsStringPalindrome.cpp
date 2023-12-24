// #Question:-

// https://www.codingninjas.com/studio/problems/check-if-the-string-is-a-palindrome_1062633

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;



bool isValid(char ch){

    if((ch >= 'a' && ch<= 'z') || (ch >= 'A' && ch <= 'Z') || (ch>= '0' &&  ch <= '9')){

        return 1;

    }

    

        return 0;

    }



    

char tolower(char ch){

    if((ch >='a' && ch <='z')||(ch >= '0' && ch <='9')){

        return ch;

    }

    else{

        return ch-'A' + 'a';

    }

}

int palindrome(string a){

    int st=0; int e = a.length()-1;

    while(st<=e){

    if(a[st]!=a[e]){

                    return 0;

                }

                else{

                    st++;e--;

                }

    }

    return 1;}

bool checkPalindrome(string s)

{

    

    string temp = "";

    int n = s.size();

    for(int i=0; i<n; i++){

        if(isValid(s[i])){

            temp.push_back(s[i]);

        } 

    }

    



    for(int i =0; i<temp.length();i++){

        temp[i] = tolower(temp[i]);

    }

return palindrome( temp );

}