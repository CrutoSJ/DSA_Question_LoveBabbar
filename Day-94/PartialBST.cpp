// #Question:-

// Link-> https://www.naukri.com/code360/problems/validate-bst_799483

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node 
    {
    public : 
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            left = NULL;    
            right = NULL;
        }
};

bool isBST(Node *root, int min, int max){
    if(root==NULL){
        return true;
    }

    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else{
        return false;
    }
}