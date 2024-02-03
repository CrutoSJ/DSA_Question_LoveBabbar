// #Question:-

// Link -> https://www.codingninjas.com/studio/problems/linked-list-cycle-ii_1112628

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

Node* isCycle(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return slow;
        }
    }

    return NULL;

}

Node* meetPoint(Node* intersection, Node* head){
    Node* head1 = head;
    Node* head2 = intersection;

    if(intersection == NULL){
        return NULL;
    }

    while(head1 != head2){

        head1 = head1->next;
        head2 = head2->next;

    }

    return head1;
}

Node *firstNode(Node *head)
{
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* intersection = isCycle(head);

    Node* point = meetPoint(intersection, head);

    return point;
}