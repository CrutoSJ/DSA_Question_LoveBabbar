// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

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
    pair<bool,int> isBalancedFast(Node* root){
        if(root==NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);
        
        bool leftA = left.first;
        bool rightA = right.first;
        
        bool diff = abs(left.second-right.second) <= 1;
        
        pair<bool,int>ans;
        ans.second = max(left.second, right.second) + 1;
        if(leftA && rightA && diff){
            ans.first = true;
        } else{
            ans.first = false;
        }
        return ans;
    }
    public:
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
};