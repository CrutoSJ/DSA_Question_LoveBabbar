// #Question:-

// Link-> https://www.naukri.com/code360/problems/h_920474

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

void findInorder(TreeNode* root, vector<int> &vec){
    if(root == NULL){
        return ;
    }

    findInorder(root->left, vec);
    vec.push_back(root->data);
    findInorder(root->right, vec);
    return ;
}

void mergeVec(vector<int> &vec, vector<int> vec1, vector<int> vec2){
    if(vec1.size() < 0 && vec2.size() < 0){
        return ;
    }

    int i=0, j=0;

    while(i<vec1.size() && j<vec2.size()){
        if(vec1[i] < vec2[j]){
            vec.push_back(vec1[i++]);
        } else{
            vec.push_back(vec2[j++]);
        }
    }

    while(i<vec1.size()){
        vec.push_back(vec1[i++]);
    }

    while(j<vec2.size()){
        vec.push_back(vec2[j++]);
    }
}

TreeNode* inOrdBST(vector<int> &vec, int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;

    TreeNode* root = new TreeNode(vec[mid]);

    root->left = inOrdBST(vec, s, mid-1);
    root->right = inOrdBST(vec, mid+1, e);

    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    //step 1 -> get the inorder traversal vectors.
    vector<int>vec1;
    vector<int>vec2;   

    findInorder(root1, vec1);
    findInorder(root2, vec2);


    //step 2 -> get the sorted - merged vector to make a BST.

    vector<int>vec;

    mergeVec(vec, vec1, vec2);

    return vec;

    //step 3 -> make BST from the sorted vector.

    //TreeNode* root = inOrdBST(vec, 0, vec.size()-1);

    //return root;




}