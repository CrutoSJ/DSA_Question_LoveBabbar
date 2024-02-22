// #Question:-

// You are given a Singly Linked List of integers with a head pointer. Every node of the Linked List has a value written on it.

//Link-> https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/651073/offering/10442134

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class Node
    {
    public:
        T data;
        Node<T> *next;
        Node()
        {
            this->data = 0;
            this->next = NULL;
        }
        Node(T data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(T data, T* next)
        {
            this->data = data;
            this->next = next;
        }
    };

int searchInLinkedList(Node<int> *head, int k) {
    Node<int> *temp = head;
    while( temp!= NULL){
        if(temp->data == k){
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}