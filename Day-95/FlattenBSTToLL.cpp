// #Question:-

// Link-> https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public : 
        int data;
        TreeNode *left;
        TreeNode *right;

    TreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void InOrder(TreeNode* root, vector<TreeNode*>& InOSeq){
    if(root == NULL){
        return ;
    }

    InOrder(root->left, InOSeq);
    InOSeq.push_back(root);
    InOrder(root->right, InOSeq);
}

TreeNode* flatten(TreeNode* root)
{
    vector<TreeNode*>InOSeq;
    InOrder(root, InOSeq);

    int n = InOSeq.size();

    for(int i=0; i<=n-2; i++){
        InOSeq[i]->left = NULL;
        InOSeq[i]->right = InOSeq[i+1];
    }
    InOSeq[n-1]->left = NULL, InOSeq[n-1]->right = NULL;
    return InOSeq[0];
}
