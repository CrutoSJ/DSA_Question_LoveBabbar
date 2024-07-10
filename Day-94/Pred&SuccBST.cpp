// #Question:-

// Link-> https://www.naukri.com/code360/problems/_893049

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

TreeNode* findPred(TreeNode *root, int key){
    TreeNode* pred = NULL;
    while(root!=NULL){
        if(root->data >= key){
            root = root->left;
        } else{
            pred = root;
            root = root->right;
        }
    }
    return pred;
}

TreeNode* findSucc(TreeNode *root, int key){
    TreeNode* succ = NULL;
    while(root!=NULL){
        if(root->data <= key){
            root = root->right;
        } else{
            succ = root;
            root = root->left;
        }
    }
    return succ;
}


pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode* pred = findPred(root, key);
    TreeNode* succ = findSucc(root, key);

    int a=-1,b=-1;

    if(pred!=NULL){
        a = pred->data;
    }
    if(succ!=NULL){
        b = succ->data;
    }
    return {a,b};
}