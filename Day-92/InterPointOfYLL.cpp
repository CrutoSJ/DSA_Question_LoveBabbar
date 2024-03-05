// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

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

int intersectPoint(Node* head1, Node* head2)
{
    if(head1==NULL || head2==NULL){
        return -1;
    }
    
    Node* t1 = head1;
    Node* t2 = head2;
    
    while(t1 != t2){
        
        t1=t1==NULL?head2:t1->next;

        t2=t2==NULL?head1:t2->next;
        
    }
    
    if(t1==NULL && t2==NULL) return -1;
    
    return t1->data;
}