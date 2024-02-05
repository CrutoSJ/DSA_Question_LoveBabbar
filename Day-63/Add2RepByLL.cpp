// #Question:- 

// Link -> https://www.codingninjas.com/studio/problems/add-two-numbers_1170520

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node() {
            this->data = 0;
            this->next = NULL;
        }
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
        Node (int data, Node *next) {
            this->data = data;
            this->next = next;
        }
    };

void insertAtTail(Node* &head, Node* &tail, int val){
    Node* temp = new Node(val);

    if(head == NULL){
        head = temp;
        tail = temp;
        return ;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

Node *Add(Node *head1, Node *head2){
int carry = 0;

  Node *ansHead = NULL;
  Node *ansTail = NULL;

while(head1 != NULL || head2 != NULL || carry != 0){

    int val1 = 0;
    if(head1 != NULL){
        val1 = head1->data;
    }

    int val2 = 0;
    if(head2 != NULL){
        val2 = head2->data;
    }

    int sum = val1 + val2 + carry;
    int digit = sum%10;

    insertAtTail(ansHead, ansTail, digit);

    carry = sum/10;

    if(head1 != NULL){
        head1 = head1->next;
    }

    if(head2 != NULL){
        head2 = head2->next;
    }
}  

return ansHead;
}

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *ans = Add(num1, num2);
    return ans;
}