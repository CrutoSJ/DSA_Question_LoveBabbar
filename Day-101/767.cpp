// #Question:-

// Link-> https://leetcode.com/problems/reorganize-string/description/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>mp;

        for(auto &i : s){
            mp[i]++;
        }

        priority_queue<pair<int, char>>maxHeap;
        string ans = "";

        for(auto &i : mp){
            maxHeap.push({i.second, i.first});
        }

        while(maxHeap.size()>1){
            auto max1 = maxHeap.top();
            maxHeap.pop();
            auto max2 = maxHeap.top();
            maxHeap.pop();

            ans.push_back(max1.second);
            ans.push_back(max2.second);

            max1.first -= 1;
            max2.first -= 1;

            if(max1.first > 0){
                maxHeap.push(max1);
            }
            if(max2.first > 0){
                maxHeap.push(max2);
            }
        }

        if(!maxHeap.empty()){
            if(maxHeap.top().first > 1){
                return "";
            } else{
                ans.push_back(maxHeap.top().second);
            }
        }

        return ans;
    }
};