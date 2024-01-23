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
private:
    void solve(ListNode* &head, ListNode* curr, ListNode* prvs){
        if(curr == NULL){
            head = prvs;
            return ;
        }
        
        ListNode* forward = curr->next;
        solve(head, forward, curr);
        curr->next = prvs;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* curr = head;
        ListNode* prvs = NULL;
        
        solve(head, curr, prvs);
        return head;
    }
};