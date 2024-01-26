// #Question:-

// Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

// Link -> https://www.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

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
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int>seen;
        
        Node* prvs = NULL;
        Node* curr = head;

        while(curr != NULL){
            if(seen.find(curr->data) != seen.end()){
                prvs->next = curr->next;
                delete(curr);
            }
            else{
                seen.insert(curr->data);
                prvs = curr;
            }
        
            curr = prvs->next;
        }
    
        return head;
    }
};

