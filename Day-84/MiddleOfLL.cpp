// #Question:-

// Link-> https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/651073/offering/10442132

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

Node *findMiddle(Node *head) {
    Node *temp1=head;
    Node *temp2=head;

    while(temp2!=NULL && temp2->next!= NULL){
        temp1=temp1->next;
        temp2=temp2->next->next;
    }

    return temp1;
}