// #Question:-

// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *FlyodCycle(ListNode *head){
        if(head == NULL){
            return head;
        }
        
    ListNode *slow = head;
    ListNode *fast = head;
        
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow){
            return fast;
        }
    }
    
    return NULL;
}
    
    ListNode *findStart(ListNode *intersection, ListNode *head){
        
        if(intersection == NULL){
            return NULL;
        }
        ListNode *head1 = head;
        ListNode *head2 = intersection;
        
        while(head1 != head2){
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return head1;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head ->next == NULL){
            return NULL;
        }
        
        ListNode *intersection = FlyodCycle(head);
        
        ListNode *start = findStart(intersection, head);
        
        return start;
    }
};

