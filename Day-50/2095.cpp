// // #Question:-

// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

// The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

// For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* pro  = head;
        ListNode* prvs = NULL;
        
        while(pro->next != NULL){
            pro = pro->next;
            if(pro->next != NULL){
                pro = pro->next;
            }
            prvs = slow;
            slow = slow->next;
        }
        
        prvs->next = slow->next;
        
        return head;
        
    }
};