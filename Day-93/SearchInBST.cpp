// #Question :-

// Link-> https://www.naukri.com/code360/problems/search-in-bst_1402878

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

bool solve(BinaryTreeNode<int> *root, int x){//Method 1 - recursive way - [O(n)] (Worst Case). 
    if(root==NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    if(x > root->data){
        return solve(root->right, x);
    }
    if(x < root->data){
        return solve(root->left, x);
    }
}

bool searchInBST2(BinaryTreeNode<int> *root, int x) {//Method 2 - By Iterative Way - SC[O(1)]
    if(root==NULL)return false;

    BinaryTreeNode<int>* temp = root;
    
    while(temp!=NULL){
        if(temp->data == x){
            return true;
        }

        else if(x > temp->data){
            temp = temp->right;
        }

        else if(x < temp->data){
            temp = temp->left;
        }
    }
    return false;
}

bool searchInBST(BinaryTreeNode<int> *root, int x) {//method 1  - By Recursion
    if(root == NULL){
        return false;
    }

    solve(root, x);
}