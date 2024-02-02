/* #Question:-

You are given the head of a Linked List. You have to move the last element to the front of the Linked List and return the list.

Link -> https://www.geeksforgeeks.org/problems/move-last-element-to-front-of-a-linked-list/0?category%255B%255D=Linked%2520List

#Solution:- */

#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode * curr = head;
        //ListNode* nxt = NULL;
        ListNode* prvs = NULL;
        
        while(curr->next != NULL){
            //nxt = curr->next;
            prvs = curr;
            curr = curr->next;
        }
        
        prvs->next = NULL;
        curr->next = head;
        head = curr;
        
        return head;
    }
};