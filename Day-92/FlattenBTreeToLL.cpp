// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

class Solution
{
    public:
    void flatten(Node *root)
    {
        if(root==NULL){
            return;
        }
        Node* curr = root;
        while(curr!=NULL){
            if(curr->left != NULL){
                Node* pred = curr->left;
                while(pred->right != NULL){
                    pred=pred->right;
                }
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr=curr->right;
        }
    }
};