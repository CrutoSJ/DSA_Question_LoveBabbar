// #Question:-

// https://www.codingninjas.com/studio/problems/unique-sorted-list_2420283

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node (int data, Node *next, Node *prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node * removeDuplicates(Node *head)
{
    Node *curr = head;
    while(curr->next != NULL){
        if(curr-> data == curr->next->data){
            Node *temp = curr->next->next;
            curr->next = temp;
            
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}