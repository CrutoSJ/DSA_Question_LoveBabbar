// #Question:-

// https://www.codingninjas.com/studio/problems/permutations-of-a-string_985254

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void solve(string str, int index, vector<string>& ans){
    if(index>=str.length()){
        ans.push_back(str);
        return ;
    }

    for(int i=index; i<str.length(); i++){
        swap(str[i], str[index]);
        solve(str, index+1, ans);
        swap(str[i], str[index]);
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    int index = 0;
    solve(str, index, ans);
    sort(ans.begin(), ans.end());
    return ans;
}