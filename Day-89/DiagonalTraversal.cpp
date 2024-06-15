// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

vector<int> diagonal(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    
    while(root!=NULL){
        ans.push_back(root->data);
        if(root->left){
            q.push(root->left);
        }
        root=root->right;
        if(root==NULL && !q.empty()){
            root=q.front();
            q.pop();
        }
    }
    return ans;
}

/* This is another approach , without using queue*/

void solve(Node* root, map<int,vector<int> >&nodes, int hd){
    if(root==NULL){
        return ;
    }
    
    nodes[hd].push_back(root->data);
    solve(root->left,nodes,hd+1);
    solve(root->right,nodes,hd);
}

vector<int> diagonal2(Node *root)
{
    map<int,vector<int> >nodes;
    vector<int>ans;
    solve(root,nodes,0);
    
    for(auto i:nodes){
        for(auto j:i.second){
            ans.push_back(j);
        }
    }
    
    return ans;
}