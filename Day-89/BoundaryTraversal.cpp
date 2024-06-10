// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
private:
    void TraverseLeft(Node* root, vector<int> &ans){
        if(root==NULL || root->left==NULL && root->right==NULL){
            return ;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            TraverseLeft(root->left, ans);
        }
        else{
            TraverseLeft(root->right,ans);
        }
        return;
    }
    
    void TraverseLeaf(Node* root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        if(root->left){
            TraverseLeaf(root->left,ans);
        }
        if(root->right){
            TraverseLeaf(root->right,ans);
        }
        return;
    }
    
    void TraverseRight(Node* root, vector<int> &ans){
        if(root==NULL || root->left==NULL && root->right==NULL){
            return ;
        }
        
        if(root->right){
            TraverseRight(root->right,ans);
            ans.push_back(root->data);
        } 
        else{
            if(root->left){
                TraverseRight(root->left,ans);
                ans.push_back(root->data);
            }
        }
        //ans.push_back(root->data);
        
        return;
    }
    
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        TraverseLeft(root->left,ans);
        
        TraverseLeaf(root->left,ans);
        TraverseLeaf(root->right,ans);
        
        TraverseRight(root->right,ans);
        
        return ans;
    }
};