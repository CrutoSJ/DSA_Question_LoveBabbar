// #Question:-

// Link-> https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333

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

int solve(Node* root, int k, int &i){
    if(root==NULL){
        return -1;
    }

    int left = solve(root->left, k, i);
    if(left!=-1){
        return left;
    }

    i++;
    if(i==k){
        return root->data;
    }

    return solve(root->right, k, i);
}


int kthSmallest(Node* root, int k) {
    int i=0;
    int ans = solve(root, k, i);
    return ans;
}

