// #Question:-

// Given head, the head of a singly linked list, find if the linked list is circular or not. A linked list is called circular if it not NULL terminated and all nodes are connected in the form of a cycle. An empty linked list is considered as circular.

// Note: The linked list does not contains any inner loop.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; 

bool isCircular(Node *head)
{
    if(head == NULL || head->next == NULL){
        return 0;
    }
    
    Node *noob = head;
    Node *pro  = head;
    
    while(pro != NULL && pro->next != NULL){
        pro = pro->next->next;
        noob = noob->next;
        
        if(pro == noob){
            return 1;
        }
    }
    
    return 0;
}