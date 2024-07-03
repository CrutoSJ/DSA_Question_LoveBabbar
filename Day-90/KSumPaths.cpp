// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/k-sum-paths/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
private:
    void solve(Node* root, int k, int &count, vector<int>paths){
        if(root == NULL){
            return ;
        }
        paths.push_back(root->data);
        solve(root->left, k, count, paths);
        solve(root->right, k, count, paths);
        
        int size = paths.size()-1;
        int sum = 0;
        for(int i=size; i>=0; i--){
            sum+=paths[i];
            if(sum == k){
                count++;
            }
        }
        paths.pop_back();
    }
public:
    int sumK(Node *root,int k)
    {
        int count = 0;
        vector<int>paths;
        solve(root, k, count, paths);
        return count;
    }
};

