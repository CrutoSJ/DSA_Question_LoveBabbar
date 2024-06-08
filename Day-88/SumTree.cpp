// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-tree/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution
{
    public:
    pair<bool,int> isSumTreeFast(Node* root){
        if(root==NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        
        if(root->left==NULL && root->right==NULL){
            pair<bool,int>p = make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> left = isSumTreeFast(root->left);
        pair<bool,int> right = isSumTreeFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool sum = (root->data == left.second+right.second);
        
        pair<bool,int>ans;
        ans.second = root->data+left.second+right.second;
        if(leftAns && rightAns && sum){
            ans.first=true;
        } else{
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root){
            return isSumTreeFast(root).first;
    }
};