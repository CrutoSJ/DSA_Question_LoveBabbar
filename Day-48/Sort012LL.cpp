// #Question:-

// https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937

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

Node* sortList(Node *head){

    int ZeroCount = 0;
    int OneCount = 0;
    int TwoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == 0){
            ZeroCount++;
        }
        else if(temp->data == 1){
            OneCount++;
        }
        else if(temp->data == 2){
            TwoCount++;
        }

        temp = temp->next;
    }

    temp = head;

    while(temp != NULL){
        if (ZeroCount != 0){
            temp -> data = 0;
            ZeroCount--;
        }
        else if(OneCount != 0 ){
            temp -> data = 1;
            OneCount--;
        }
        else if(TwoCount != 0){
            temp -> data = 2;
            TwoCount--;
        }

        temp = temp->next;
    }

    return head;
}