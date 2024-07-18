// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void heapify(vector<int> &ans, int size, int idx){
        int largest = idx;
        
        int left = 2*idx+1;
        int right = 2*idx+2;
        
        if(left < size && ans[largest] < ans[left]){
            largest = left;
        }
        
        if(right < size && ans[largest] < ans[right]){
            largest = right;
        }
        
        if(largest != idx){
            swap(ans[largest], ans[idx]);
            heapify(ans, size, largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>ans(n+m);
        
        merge(a.begin(), a.end(), b.begin(), b.end(), ans.begin());
        
        int size = ans.size();
        
        for(int i=size/2-1; i>=0; i--){
            heapify(ans, size, i);
        }
        
        return ans;
    }
};