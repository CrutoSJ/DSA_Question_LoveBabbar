// #Question:-

// Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL){
            return head;
        }

        ListNode* prvs = NULL;
        ListNode* curr = head;
        ListNode* temp = NULL;
        
        while(curr != NULL){
            temp = curr->next;
            curr->next = prvs;
            prvs = curr;
            curr = temp;
        }
        return prvs;
    }
};