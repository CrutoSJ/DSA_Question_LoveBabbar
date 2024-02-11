// #Question:-

// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<char> st;
        stack<string> ans;

        for(int i=0; i<n; i++){
            string temp = "";
            if(s[i] != ' '){
                st.push(s[i]);
            }
            else{
                while(!st.empty()){
                    temp.push_back(st.top());
                    st.pop();
                }

                if(temp.size() != 0){
                    reverse(temp.begin(), temp.end());
                    ans.push(temp);
                }
            }
        }

        string temp = "";
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        if(temp.size() != 0){
            reverse(temp.begin(), temp.end());
            ans.push(temp);
        }

        string finalAns = "";
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            finalAns += ans.top();
            finalAns += " ";
            ans.pop();
        }

        finalAns = finalAns.substr(0, finalAns.size()-1);

        return finalAns;
    }
};