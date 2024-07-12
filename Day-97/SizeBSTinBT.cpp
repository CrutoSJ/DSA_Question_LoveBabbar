// #Question:-

// Link-> https://www.naukri.com/code360/problems/largest-bst-subtree_893103

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

class info{
    public:
        int maxi;
        int mini;
        bool isBSt;
        int size;
};

info solve(TreeNode* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.mini = min(root->data, left.mini);
    currNode.maxi = max(root->data, right.maxi);

    if(left.isBSt && right.isBSt && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBSt = true;
    } else{
        currNode.isBSt = false;
    }

    if(currNode.isBSt){
        ans = max(ans, currNode.size);
    }
    
    return currNode;
}


int largestBST(TreeNode * root){
    int maxSize=0;
    info ans = solve(root, maxSize);
    return maxSize;

}