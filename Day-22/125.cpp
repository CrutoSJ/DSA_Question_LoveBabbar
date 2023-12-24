// #Question:-

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
    
private:
    
    bool isValid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }
        
        else{
            return 0;
        }
    }
    
    char toLower(char ch){
        if((ch >= 'a' && ch <= 'z') ||  (ch >= '0' && ch <= '9')){
            return ch;
        }
        
        else{
            char temp = ch - 'A' + 'a'; 
            return temp;
        }
    }
    
    bool checkPalindrome(string s){
        int str=0;
        int e=s.length()-1;
        
        while(str<=e){
            if(s[str]!=s[e]){
                return 0;
            }
            
            else{
                str++;
                e--;
            }
        }
        return 1;
    }
    
    
    
public:
    bool isPalindrome(string s) {
        
        string temp ="";
        
        for(int i=0; i<s.length(); i++){
            if(isValid(s[i])){
                temp.push_back(s[i]);
            }
        }
        
        for(int i=0; i<temp.length(); i++){
            temp[i] = toLower(temp[i]);
        }
        
        return checkPalindrome(temp);
        
    }
};