// #Question:-

// Link-> https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

    BinaryTreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void InOrder(BinaryTreeNode* root, vector<int> &InOSeq){
    if(root == NULL){
        return ;
    }

    InOrder(root->left, InOSeq);
    InOSeq.push_back(root->data);
    InOrder(root->right, InOSeq);
}

bool twoSumInBST(BinaryTreeNode* root, int target) {
	vector<int>InOSeq;
    InOrder(root, InOSeq);

    int s=0, e=InOSeq.size()-1;
    while(s<e){
        int sum = InOSeq[s] + InOSeq[e];
        if(sum == target){
            return true;
        } else if(sum > target){
            e--;
        } else{
            s++;
        }
    }
    return false;
}