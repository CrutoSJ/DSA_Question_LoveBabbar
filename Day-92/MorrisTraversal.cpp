// #Question:-

// Morris Traversal Algo - print Tree in inOrderTraversal 
//Inorder Tree Traversal without recursion and without stack!

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct tNode{
    int data;
    tNode* left;
    tNode* right;
};

struct tNode* newTNode (int data){
    tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

void MorrisTraversal(tNode* root){
    if(root == NULL){
        return ;
    }

    tNode* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            tNode* pred = curr->left;
            while(pred->right && pred->right != curr){
                pred=pred->right;
            }
            if(pred->right == NULL){
                pred->right = curr;
                curr=curr->left;
            }
            else{
                pred->right = NULL;
                cout << curr->data << " ";
                curr=curr->right;
            }
        }
    }
}

int main(){
    tNode* root = newTNode(1);
    root->left = newTNode(2);
    root->right = newTNode(3);
    root->left->left = newTNode(4);
    root->left->right = newTNode(5);

    MorrisTraversal(root);

    return 0;
}