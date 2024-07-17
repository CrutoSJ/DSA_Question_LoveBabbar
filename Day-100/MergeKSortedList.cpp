// #Question:-

// Link-> https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772

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

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare>minHeap;

    int size = listArray.size();

    for(int i=0; i<size; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    while(!minHeap.empty()){
        Node* temp = minHeap.top();

        if(temp->next != NULL){
            minHeap.push(temp->next);
        }


        minHeap.pop();
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    return head;
}
