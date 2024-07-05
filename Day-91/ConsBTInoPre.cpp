// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
private:
    int findPos(int in[], int element, int start, int end){
        for(int i=start; i<=end; i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n){
        if(index<0 || inOrderStart>inOrderEnd){
            return NULL;
        }
        int element = post[index--];
        Node* root = new Node(element);
        int pos = findPos(in, element, inOrderStart, inOrderEnd);
        if(pos == -1){
            return NULL;
        }
        
        root->right = solve(in, post, index, pos+1, inOrderEnd, n);
        root->left = solve(in, post, index, inOrderStart, pos-1, n);
        
        return root;
    }
public:
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderIndex = n-1;
        Node* ans = solve(in, post, postOrderIndex, 0, n-1, n);
        return ans;
    }
};
