// #Question:-

// Given a linked list of N nodes. The task is to check if the linked list has a loop. Linked list can contain self loop.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node *slow = head;
        Node *pro  = head;
        
        if(head == NULL || head->next == NULL){
            return false;
        }
        
        while( pro-> next != NULL && pro->next->next != NULL){
            pro = pro -> next -> next;
            slow = slow -> next;
            
            if(pro == slow){
                return true;
            }
        }
        
        return false;
    }
};
