// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        if(root==NULL){
            return 0;
        }
        
        int left=height(root->left);
        int right=height(root->right);
        int ans = max(left,right)+1;
        return ans;
    }
};