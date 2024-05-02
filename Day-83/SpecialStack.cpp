// #Question:-

// Link-> https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class SpecialStack {
    public:
    stack<int>s;
    int mini;
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else{
            if(data<mini){
                s.push(2*data-mini);
                mini = data;
            }

            else{
                s.push(data);
            }
        }
    }

    void pop() {
        if(s.empty()){
            return ;
        }

        int curr = s.top();
        s.pop();

        if(curr > mini){
            return ;
        }
        else{
            int val = 2*mini - curr;
            mini = val;
            return ;
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }

        int curr = s.top();

        if(curr < mini){
            return mini;
        }

        else{
            return curr;
        }
    }

    int getMin() {
        return mini;
    }  
};