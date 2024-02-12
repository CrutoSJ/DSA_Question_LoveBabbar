// #Question:-

// Link -> https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770

// #Solution:-

#include <bits/stdc++.h>
using namespace std; 
int findMinimumCost(string str) {
if(str.length() % 2 == 1){
    return -1;
}

stack<char> S;
for(int i=0; i<str.length(); i++){
    char ch = str[i];

    if(ch == '{'){
        S.push(ch);
    }
    else{
        //closing bracket agaya...
        if(!S.empty() && S.top() == '{'){
            S.pop();
        }
        else{
            S.push(ch);
        }
    }
}

int a = 0;
int b = 0;

while(!S.empty()){
    if(S.top() == '{'){
        a++;
    }
    else{
        b++;
    }
    S.pop();
}

int ans = (a+1)/2 + (b+1)/2;

return ans;


}