// #Question:-

// #Link-> https://www.naukri.com/code360/problems/queue-using-array-or-singly-linked-list_2099908

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

class Queue {

    int* arr;
    int qfront;
    int rear;
    int size;


public:
    Queue() {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(rear==qfront){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        if(rear == size){
            return ;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(rear==qfront){
            return -1;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int front() {
        if(rear==qfront){
            return -1;
        }

        else{
            return arr[qfront];
        }
    }
};