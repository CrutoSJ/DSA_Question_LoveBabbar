// #Question:-

// Link-> https://www.naukri.com/code360/problems/count-leaf-nodes_893055

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
};

void postOrder(BinaryTreeNode<int> *root, int& cnt){
    if(root == NULL){
        return ;
    }

    postOrder(root->left, cnt);
    postOrder(root->right, cnt);
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt = 0;
    postOrder(root, cnt);
    return cnt;
}