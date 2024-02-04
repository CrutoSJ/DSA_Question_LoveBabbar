#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];

    }

    void push(int element){
        if(size-top > 1){
            top++;
            arr[top] = element;
            cout << "push operation performed, innserted "<< element << endl; 
        }
        else{
            cout << "Stack overflow" << endl;
        }
    }

    int pop(){
        if(top<size){
            top--;
            int ans = arr[top];
            cout << "pop operation performed, poped "<< top << endl; 
            return ans;
        }

        else{
            return -1;
        }
    }

    int peek(){
        if(top<size && top>=0){
            cout << "peek operation performed, peek elemet is "<< arr[top] << endl; 
            return arr[top];
        }
        else{
            return -1;
        }
    }

    bool isEmpty(){
        if(top>=0 && top<size){
            return false;
        }
        else{
            return true;
        }
    }

};

int main(){

    Stack stk(5);

    stk.push(20);
    stk.push(45);
    stk.push(100);
    stk.push(150);
    stk.push(250);
    stk.push(12);

    cout << stk.peek() << endl;


    if(stk.isEmpty()){
        cout << "Stack is Empty" << endl;
    }
    else{
        cout << "Stack is non-Empty" << endl;
    }

return 0;

}