// #Question:-

// Given a singly linked list of N nodes. Find the first node of the loop if the linked list has a loop. If a loop is present return the node data of the first node of the loop else return -1.

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
    private:
    Node* findLoopStart(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(slow->next != NULL && fast->next != NULL ){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }
        
        if(slow == fast) break;
    }
    if(slow != fast || slow == NULL || fast == NULL) return NULL;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        Node* temp = findLoopStart(head);
        if(temp == NULL) return -1;
        return temp->data;
    }
};