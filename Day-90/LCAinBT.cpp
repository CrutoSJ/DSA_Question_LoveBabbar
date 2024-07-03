// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

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

class Solution
{
    private:
    Node* solve(Node* root, int n1, int n2){
        if(root==NULL){
            return NULL;
        }
        if(root->data == n1 || root->data == n2){
            return root;
        }
        
        Node* leftT = solve(root->left, n1, n2);
        Node* rightT = solve(root->right, n1, n2);
        if(leftT != NULL && rightT != NULL){
            return root;
        } else if(leftT != NULL && rightT == NULL){
            return leftT;
        } else if(leftT == NULL && rightT != NULL){
            return rightT;
        } else{
            return NULL;
        }
    }
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        return solve(root, n1, n2);
    }
};