// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* Successor = NULL;
        
        while(root!=NULL){
            if(root->data <= x->data){
                root=root->right;
            } else{
                Successor = root;
                root=root->left;
            }
        }
        return Successor;
    }
};