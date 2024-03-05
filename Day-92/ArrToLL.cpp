// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/introduction-to-linked-list_8144737

// #SOlution:-


#include<bits/stdc++.h>
using namespace std;

class Node {
    
    public:
        int data;
        Node* next;
        Node() : data(0), next(nullptr) {}
        Node(int x) : data(x), next(nullptr) {}
        Node(int x, Node* next) : data(x), next(next) {}
    };

Node* constructLL(vector<int>& arr) {
    
    Node* head = NULL;
    while(arr.size()!=0){
        int val = arr.back();

        Node* temp = new Node(val);

        if(head == NULL){
            head=temp;
        } else{
            temp->next = head;
            head = temp;
        }
        arr.pop_back();
    }

    return head;
}
