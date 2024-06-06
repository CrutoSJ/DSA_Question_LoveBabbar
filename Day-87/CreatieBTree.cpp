#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* BinTree(node* root){
    cout << "Enter the data for node: ";
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1) return NULL;

    cout << "Enter data for left of " << data << ":" << endl;
    root->left = BinTree(root->left);
    cout << "Enter data for right of " << data << ":" << endl;
    root->right = BinTree(root->right);

    return root;
}

void levelOrderTrav(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } 

        else{
            cout << temp->data << " ";
            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
};


int main(){
    node* root = NULL;
    root = BinTree(root);

    cout << endl << "Printing level order Traversal"<<endl;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTrav(root);
    return 0;
}