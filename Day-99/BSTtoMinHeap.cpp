// #Question:-

// Link-> https://www.naukri.com/code360/problems/convert-bst-to-min-heap_920498

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
};

void InOrdTrav(BinaryTreeNode* root, vector<int> &ans){
	if(root == NULL){
		return ;
	}

	InOrdTrav(root->left, ans);
	ans.push_back(root->data);
	InOrdTrav(root->right, ans);
	return ;
}

void fillPreOrd(BinaryTreeNode* root, vector<int> ans, int &i){
	if(i>=ans.size()){
		return ;
	}

	root->data = ans[i++];
	if(root->left)fillPreOrd(root->left, ans, i);
	if(root->right)fillPreOrd(root->right, ans, i);
	return ;
}


BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int>ans;
	InOrdTrav(root, ans);

	int index = 0;
	fillPreOrd(root, ans, index);
	return root;

}