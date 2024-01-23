// #Question:-

// Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
// Note: Try not to use extra space. The nodes are arranged in a sorted way.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    
if(head == NULL || head->next == NULL){
    return head;
}

Node* curr = head;

while(curr != NULL && curr->next != NULL){
    if(curr->data == curr->next->data ){
        Node* temp = curr->next->next;
        curr->next = temp; 
    }
    else{
        curr = curr->next;
    }
}
return head;

}