#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* root, int d){
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        root->right = insertInBST(root->right, d);
    }
    else if(d < root->data){
        root->left = insertInBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertInBST(root, data);
        cin >> data;
    }
}

void levelOrderTrav(Node* root){
    if(root == NULL){
        return ;
    }

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int s = q.size();
        for(int i=0; i<s; i++){
            Node* front = q.front();
            q.pop();
            cout << front->data << endl;
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        
    }
}

void inOrderTrav(Node* root){
    if(root == NULL){
        return ;
    }

    inOrderTrav(root->left);
    cout << root->data << " ";
    inOrderTrav(root->right);

    return ;
}

void preOrder(Node* root){
    if(root==NULL){
        return  ;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

    return;
}

void postorder(Node* root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

    return ;
}

Node* minVal(Node* root){
    if(root == NULL){
        return root;
    }
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    if(root == NULL){
        return root;
    }
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteNode(Node* root, int x){
    if(root == NULL){
        return root;
    }

    if(root->data == x){//found the node
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child ( left child ):-

        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //1 child (right child):-
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int min = minVal(root->right) -> data;
            root->data = min;
            root->right = deleteNode(root->right, min);
            return root;
        }
    }

    else if(x > root->data){
        root->right = deleteNode(root->right, x);
        return root;
    }

    else{
        root->left = deleteNode(root->left, x);
        return root;
    }
}


int main(){
    Node* root = NULL;

    cout << "Enter root for BST: " << endl;
    takeInput(root);

    cout << "Printing level Order: " << endl;
    levelOrderTrav(root);
    cout  << endl;

    cout << "Printing in Order: " << endl;
    inOrderTrav(root);
    cout  << endl;

    cout << "Printing pre Order: " << endl;
    preOrder(root);
    cout  << endl;

    cout << "Printing post Order: " << endl;
    postorder(root);
    cout  << endl;

    cout << "Min Val: " << minVal(root) -> data << endl ;
    cout << "Max Val: " << maxVal(root) -> data << endl;
    cout << endl;

    root = deleteNode(root, 50);

    cout << "After deleteion : " << endl;
    cout << endl;

    cout << "Printing level Order: " << endl;
    levelOrderTrav(root);
    cout  << endl;

    cout << "Printing in Order: " << endl;
    inOrderTrav(root);
    cout  << endl;

    cout << "Printing pre Order: " << endl;
    preOrder(root);
    cout  << endl;

    cout << "Printing post Order: " << endl;
    postorder(root);
    cout  << endl;

    cout << "Min Val: " << minVal(root) -> data << endl ;
    cout << "Max Val: " << maxVal(root) -> data << endl;

    return 0;
}