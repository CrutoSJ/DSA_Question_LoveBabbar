// #Question:-

// Link-> https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

void InOrder(TreeNode<int>* root, vector<int>& InOSeq){
    if(root==NULL){
        return ;
    }

    InOrder(root->left, InOSeq);
    InOSeq.push_back(root->data);
    InOrder(root->right, InOSeq);
}

TreeNode<int>* ToBST(vector<int> InOSeq, int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode<int>* NRoot = new TreeNode<int>(InOSeq[mid]);

    NRoot->left = ToBST(InOSeq, s, mid-1);
    NRoot->right = ToBST(InOSeq, mid+1, e);
    return NRoot;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int>InOSeq;
    InOrder(root, InOSeq);

    int s=0, e=InOSeq.size()-1;
    return ToBST(InOSeq, s, e);
}
