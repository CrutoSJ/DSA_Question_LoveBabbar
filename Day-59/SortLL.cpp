// #Question:-

// Link -> https://www.codingninjas.com/studio/problems/sort-linked-list_625193

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* findMid(Node *head){
    Node *noob = head;
    Node *pro = head->next;

    while(pro != NULL && pro->next != NULL){
        noob = noob->next;
        pro = pro -> next -> next;
    }

    return noob;
}

Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node *ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node* sortList(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    //sort the 2 parts:-

    left = sortList(left);
    right = sortList(right);

    // merge the two parts:-

    Node *ans = merge(left, right);
    return ans;

};