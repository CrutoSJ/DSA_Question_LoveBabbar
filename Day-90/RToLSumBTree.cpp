// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    void solve(Node *root, int l, int &maxL, int s, int &maxS){
        if(root == NULL){
            if(l>maxL){
                maxL=l;
                maxS=s;
            }
            else if(l==maxL){
                maxS = max(s,maxS);
            }
            return;
        }
        s = s+root->data;
        solve(root->left, l+1, maxL, s, maxS);
        solve(root->right, l+1, maxL, s, maxS);
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int l=0;
        int maxL=0;
        
        int s=0;
        int maxS=0;
        
        solve(root, l, maxL, s, maxS);
        
        return maxS;
    }
};