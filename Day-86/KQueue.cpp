#include<bits/stdc++.h>
using namespace std;

class kQueue{
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int *next;
        int freeSpot;

    public:
        kQueue(int n, int k){
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;

            arr = new int[n];
            freeSpot = 0;
        }

        void enqueue(int data, int qn){
            //check for overflow:-
            if(freeSpot == -1){
                cout << "Queue is full." << endl;
                return ;
            }

            //place where to insert:-
            int index = freeSpot;

            //update freeSpot, for next element to be inserted
            freeSpot = next[index];

            //check if inserting for 1st time or not?
            if(front[qn-1] == -1){
                front[qn-1] = index;
            } else{
                next[rear[qn-1]] = index;
            }

            //update status of next
            next[index] = -1;

            //update the rear:-
            rear[qn-1] = index;

            //put the element in arr:-
            arr[index] = data;

            return;
        }

        int dequeue(int qn){
            //check for underflow:-
            if(front[qn-1] == -1){
                cout<< "Queue underflow" << endl;
                return -1;
            }

            //find index where to delete from
            int index = front[qn-1];

            //update the front[]:-
            front[qn-1] = next[index];

            //update next[]:-
            next[index] = freeSpot;

            //update freeSpot:-
            freeSpot = index;

            return arr[index];
        }

};

int main(){

    kQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

    return 0;
}