// #Question:-

// https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void revLL(LinkedListNode<int>* &head, LinkedListNode<int>* curr, LinkedListNode<int>* prvs ){

    

    if(curr == NULL){
        head = prvs;
        return ;
    }

    LinkedListNode<int>* forward = curr -> next;
    revLL(head, forward, curr);
    curr -> next = prvs;
    
}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head -> next == NULL ){
        return head;
    }

    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* prvs = NULL;

    revLL(head, curr, prvs);
    return head;
}