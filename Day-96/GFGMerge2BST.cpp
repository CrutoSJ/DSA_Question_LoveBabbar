// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
private:
    
    void bstToLL(Node* root, Node* &head){
        if(root == NULL){
            return ;
        }
        
        bstToLL(root->right, head);
        root->right = head;
        if(head!=NULL){
            head->left = root;
        }
        head = root;
        
        bstToLL(root->left, head);
        
    }
    
    Node* mergeLL(Node* head1, Node* head2){
        if(head1 == NULL && head2 == NULL){
            return NULL;
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        
        while(head1!=NULL && head2!=NULL){
            if(head1->data < head2->data){
                if(head==NULL){
                    head = head1;
                    tail = head1;
                    head1=head1->right;
                }
                else{
                    tail->right = head1;
                    tail = tail->right;
                    head1=head1->right;
                }
            }
            else{
                if(head==NULL){
                    head = head2;
                    tail = head2;
                    head2=head2->right;
                }
                else{
                    tail->right = head2;
                    tail = tail->right;
                    head2=head2->right;
                }
            }
        }
        
        while(head1!=NULL){
            tail->right = head1;
            tail = tail->right;
            head1=head1->right;
        }
        
        while(head2!=NULL){
            tail->right = head2;
            tail = tail->right;
            head2=head2->right;
        }
        
        return head;
    }
    
    void LLToVec(vector<int> &ans, Node* root){
        if(root == NULL){
            return ;
        }
        Node* temp = root;
        while(temp!=NULL){
            ans.push_back(temp->data);
            temp=temp->right;
        }
        return ;
    }
    
    
    
public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        Node* head1 = NULL; 
        bstToLL(root1, head1);
        head1->left = NULL;
        
        Node* head2 = NULL;
        bstToLL(root2, head2);
        head2->left = NULL;
        
        Node* root = mergeLL(head1, head2);
        
        vector<int>ans;
        
        LLToVec(ans, root);
        return ans;
        
        
    }
};