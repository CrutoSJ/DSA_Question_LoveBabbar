// #Question:-

// Link ->  https://www.codingninjas.com/studio/problems/-intersection-of-two-linked-lists_630457

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

Node* findIntersection(Node *firstHead, Node *secondHead){
    if(firstHead == NULL || secondHead == NULL){
        return NULL;
    }

    Node *Head1 = firstHead;
    Node *Head2 = secondHead;

    while(Head1 != Head2){
        Head1 = Head1->next;
        Head2 = Head2->next;

        if(Head1 == Head2){
            return Head1;
        }

        if(Head1 == NULL){
            Head1 = secondHead;
        }

        if (Head2 == NULL) {
            Head2 = firstHead;
        }
    }

    return Head1;
}