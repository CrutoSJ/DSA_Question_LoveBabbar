// #Question:-

// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

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

class Solution
{
    private:
    Node* reverseList(struct Node *head){
        Node* prvs = NULL;
        Node* curr = head;
        while(curr != NULL){
            Node* nxt = curr->next;
            curr->next = prvs;
            prvs = curr;
            curr = nxt;
        }
        return prvs;
    
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* newHead = reverseList(head);
        Node* ptr = newHead;
        int carry = 1;
        while(ptr != NULL){
            ptr->data = ptr->data+carry;
            if(ptr->data <10){
                carry = 0;
                break;
            }
            else{
                ptr->data = 0;
                carry = 1;
            }
            ptr = ptr->next;
        }
        if(carry == 1){
            Node* newNode = new Node(1);
            newNode->next = reverseList(newHead);
            return newNode;
        }
        Node* node = reverseList(newHead);
        return node;
    }
};