// #Question:-

// Link-> https://www.codingninjas.com/studio/problems/segregate-even-and-odd-nodes-in-a-linked-list_1116100

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
		int data;
  		Node *next;
		Node() : data(0), next(nullptr) {};
		Node(int x) : data(x), next(nullptr) {}
 		Node(int x, Node *next) : data(x), next(next) {}
    };

Node* segregateEvenOdd(Node* head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }


    Node* even = new Node(-1);
    Node* odd  = new Node(-1);

    Node* evenTail = even;
    Node* oddTail  = odd;

    Node* curr = head;

    while(curr != NULL){
        if(curr->data %2 == 0){
            evenTail->next = curr;
            evenTail = curr;
        }
        else{
            oddTail->next = curr;
            oddTail = curr;
        }
        
        curr = curr->next;
    }

    evenTail->next = odd->next;
    oddTail ->next = NULL;

    Node* result = even->next;

    delete even;
    delete odd; 

    return result;
}
