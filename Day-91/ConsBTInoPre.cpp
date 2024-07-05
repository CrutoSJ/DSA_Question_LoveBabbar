// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/construct-tree-1/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    private:
    int findPos(int in[], int element, int start, int end){
        for(int i=start; i<=end; i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        int element = pre[index++];
        Node* root = new Node(element);
        int pos = findPos(in, element, inOrderStart, inOrderEnd);
        if(pos == -1) return NULL;
        root->left = solve(in, pre, index, inOrderStart, pos-1, n);
        root->right = solve(in, pre, index, pos+1, inOrderEnd, n);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};