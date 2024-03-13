// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

// twoStacks : Initialize the data structures and variables to be used to implement  2 stacks in one array.
// push1 : pushes element into first stack.
// push2 : pushes element into second stack.
// pop1 : pops element from first stack and returns the popped element. If first stack is empty, it should return -1.
// pop2 : pops element from second stack and returns the popped element. If second stack is empty, it should return -1.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class twoStacks
{
    public:
    
    int *arr;
    int top1;
    int top2;
    int size;
    
    
    twoStacks()
    {
        this->size = 1000;
        arr = new int[size];
        top1 = -1;
        top2 = size;
        
    }

    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top2-top1>1){
            top1++;
            arr[top1] = x;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
        if(top2-top1>1){
            top2--;
            arr[top2] = x;
        }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        } else{
            return -1;
        }
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
            if(top2<size){
            int ans = arr[top2];
            top2++;
                return ans;
            } else{
                return -1;
            }
    }
};