// #Question:-

// https://www.codingninjas.com/studio/problems/check-if-linked-list-is-palindrome_985248

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

Node* reverse(Node* head){
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

Node* midofList(Node* head){
    Node* slow = head;
    Node* pro  = head->next;

    while(pro != NULL && pro->next != NULL){
        slow = slow->next;
        pro = pro->next->next;
    }

    return slow;
}

bool isPalindrome(Node *head)
{

    if(head->next == NULL){
        return true;
    }

    Node* mid = midofList(head);

    Node* revstart = mid->next;
    mid->next  = reverse(revstart);

    Node* head1= head;
    Node* head2= mid->next;

    while(head2 != NULL){
        if(head1->data != head2->data){
            return 0;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    revstart = mid->next;
    mid->next = reverse(revstart);

    return 1;
    
}