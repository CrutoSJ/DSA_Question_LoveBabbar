// #Question:-

// Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution
{
    private:
        struct Node* revList(Node* head){
            Node* curr = head;
            Node* prvs = NULL;
            Node* next = NULL;
            
            while( curr != NULL){
                next = curr->next;
                curr->next = prvs;
                prvs = curr;
                curr = next;
            }
            
            return prvs;
        }
        
        void insertAtTail(struct Node* &head, struct Node* &tail, int val){
            Node* temp = new Node(val);
            
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
        
        struct Node* add(struct Node* first, struct Node* second){
            int carry = 0; 
            
            Node* ansHead = NULL;
            Node* ansTail = NULL;
            
            while(first != NULL && second != NULL){
                int sum = carry + first->data + second->data;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                
                first = first->next;
                second = second->next;
            }
            
            while(first != NULL){
                int sum = carry + first->data;
                int digit = sum%10;
                insertAtTail(ansHead, ansTail, digit);
                carry = sum/10;
                
                first = first->next;
            }
            
            while(second != NULL){
                int sum = carry + second->data;
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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* revFirst  = revList(first);
        Node* revSecond = revList(second);
        
        Node* ans = add(revFirst, revSecond);
        
        ans = revList(ans);
        
        return ans;
    }
};