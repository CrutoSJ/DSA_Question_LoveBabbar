// #Question:-

// https://www.codingninjas.com/studio/problems/duplicate-in-array_893397

// #Solution:-
#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    // Write your code here
    int sum=0;

    for(int i=0; i<arr.size(); i++){
        sum=sum^arr[i];
    }

    for(int i=1; i<arr.size(); i++){
        sum=sum^i;
    }

    return sum;
	
}
