// #Question:-

// https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list. */
    class Node {
    public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node* kReverse(Node* head, int k) {
    
    if(head == NULL){
        return head;
    }

    Node* prvs = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    int remaining = 0;
    Node* temp = head;

    while(temp != NULL && remaining < k){
        temp = temp -> next;
        remaining++;
    }

    if(remaining != k){
        return head;
    }

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prvs;
        prvs = curr;
        curr = next;
        count++;
    }
    
    if(next != NULL){
        head -> next = kReverse(next, k);
    }

    return prvs;
}