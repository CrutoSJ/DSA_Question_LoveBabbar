// #Question:-

// Link-> https://www.naukri.com/code360/problems/lca-in-a-bst_981280

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

TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    
    if(root-> data < P->data && root->data < Q->data){
        return LCAinaBST(root->right, P, Q);
    }

    else if(root-> data > P->data && root->data > Q->data){
        return LCAinaBST(root->left, P, Q);
    }

    return root;

}