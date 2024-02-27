// #Question:-

// Link-> https://www.codingninjas.com/studio/guided-paths/data-structures-algorithms/content/651073/offering/10442133

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

Node* reverseLinkedList(Node *head)
{
 stack<int>st;

 Node* temp=head;

 while(temp)

{

 st.push(temp->data);

 temp=temp->next;

}

 temp=head;

  while(!st.empty())

{

 temp->data=st.top();

 st.pop();

 temp=temp->next;

}

 return head;
}
