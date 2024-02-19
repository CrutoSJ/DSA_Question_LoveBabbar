// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// Given two linked lists sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made with without changing the original lists.

// Note: The elements of the linked list are not necessarily distinct.


// #Solution:-

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

class Solution
{
    private:
    Node* solve(Node* head1, Node* head2){
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data == temp2->data){
                ans->next = new Node(temp1->data);
                ans = ans->next;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->data > temp2->data){
                temp2 = temp2->next;
            }
            else{
                temp1 = temp1->next;
            }
        }
        
        return temp->next;
    }
    
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        if(head1 == NULL || head2 == NULL){
            return NULL;
        }
        
        Node* ans = solve(head1,head2);
        return ans;
    }
};