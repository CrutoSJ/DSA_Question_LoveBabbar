// #Question:-

// https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250

// #Solution:-

/*
Following is the class structure of the Node class:*/

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

Node* solve(Node* &head, Node *pro, Node *noob){
    if(head == NULL || head->next==NULL){
        return head;
    }

    if(head->next->next == NULL){
        return head -> next;
    }

    while(pro != NULL){
        pro = pro->next;
        if(pro !=NULL){
            pro = pro -> next;
        }
        noob = noob->next;
    }
    return noob;


}

Node *findMiddle(Node *head) {

    Node *pro = head -> next;
    Node *noob = head; 
    
    return solve(head, pro, noob);

}

