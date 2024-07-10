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

void InOrder(TreeNode* root, vector<int>& InOSeq){
    if(root == NULL){
        return ;
    }

    InOrder(root->left, InOSeq);
    InOSeq.push_back(root->data);
    InOrder(root->right, InOSeq);
}

TreeNode* flatten(TreeNode* root)
{
    vector<int>InOSeq;
    InOrder(root, InOSeq);

    int n = InOSeq.size();

    TreeNode* NRoot = new TreeNode(InOSeq[0]);
    TreeNode* RTemp = NRoot;

    for(int i=1; i<n; i++){
        TreeNode* temp = new TreeNode(InOSeq[i]);
        RTemp->left = NULL;
        RTemp->right = temp;
        RTemp = temp;
    }

    RTemp->left = NULL;
    RTemp->right = NULL;
    return NRoot;
    
}
