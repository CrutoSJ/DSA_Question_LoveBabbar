// #Question:-

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head ;
        }
        
        ListNode* prvs = NULL;
        ListNode* curr = head;
        ListNode* nxt  = NULL;
        int cnt = 0;
        
        int remaining = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL && remaining<k){
            temp = temp->next;
            remaining++;
        }
        
        if(remaining != k){
            return head;
        }
        
        while(curr != NULL && cnt<k){
            nxt = curr->next;
            curr->next = prvs;
            prvs = curr;
            curr = nxt;
            cnt++;
        }
        
        if(nxt != NULL ){
            head->next = reverseKGroup(nxt, k);
        }
        
        return prvs;
    }
};