// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{   
private:
    Node* findSuc(Node* root, int key){
        Node* Suc = NULL;
        while(root!=NULL){
            if(root->key <= key){
                root=root->right;
            } else{
                Suc = root;
                root=root->left;
            }
        }
        return Suc;
    }
    
    Node* findPre(Node* root, int key){
        Node* Pre = NULL;
        while(root!=NULL){
            if(root->key >= key){
                root=root->left;
            } else{
                Pre = root;
                root=root->right;
            }
        }
        return Pre;
    }
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = findPre(root, key);
        suc = findSuc(root, key);
        
        if(pre == NULL || suc == NULL){
            pre == NULL;
            suc == NULL;
        }
        return ;
    }
};