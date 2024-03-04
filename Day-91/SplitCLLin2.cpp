// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node* slow = head;
    Node* fast = head;
    while(fast->next != head && fast->next->next != head){
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node *temp = slow->next;
    slow->next = head;
    *head1_ref = head;
    *head2_ref = temp;
    fast = *head2_ref;
    while(fast->next != head){
        fast = fast->next;
    }
    fast->next = *head2_ref;
}