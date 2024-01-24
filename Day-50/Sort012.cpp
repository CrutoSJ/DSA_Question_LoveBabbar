// #Question:-

// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all 
// zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

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

class Solution
{
    private:
    
        void insertAtTail(Node* &tail, Node* curr){
            tail->next = curr;
            tail = curr;
        }
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        Node* zeroHead = new Node(-1);
        Node* zeroTail = zeroHead;
        Node* oneHead  = new Node(-1);
        Node* oneTail  = oneHead;
        Node* twoHead  = new Node(-1);
        Node* twoTail  = twoHead;
        
        Node* curr = head;
        
        while(curr != NULL){
            
            int value = curr->data;
            
            if(value == 0){
                insertAtTail(zeroTail, curr);
            }
            
            if(value == 1){
                insertAtTail(oneTail, curr);
            }
            
            if(value == 2){
                insertAtTail(twoTail, curr);
            }
            
            curr = curr->next;
        }
        
        if(oneHead->next != NULL){
            zeroTail->next = oneHead->next;
        }
        else{
            zeroTail->next = twoHead->next;
        }
        
        oneTail->next = twoHead->next;
        twoTail->next = NULL;
        
        head = zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
    }
};