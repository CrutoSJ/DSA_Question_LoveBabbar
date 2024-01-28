// #Question:-

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
            ListNode* temp = new ListNode(val);
            
            if(head == NULL){
                head = temp;
                tail = temp;
                return ;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
            
        }
    
    ListNode* Add(ListNode* first, ListNode* second){
        int carry = 0;
        
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        
        while(first != NULL && second != NULL){
            int sum = carry + first->val + second->val;
            int digit = sum%10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            
            first = first->next;
            second = second->next;
        }
        
        while(first != NULL){
                int sum = carry + first->val;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                
                first = first->next;
        }
        
        while(second != NULL){
                int sum = carry + second->val;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                
                second = second->next;
        }
            
        while(carry != 0){
                int sum = carry;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
        }
            
        return ansHead;
        
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Ans = Add(l1, l2);
        return Ans;
    }
};