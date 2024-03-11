// #Question:-

// Link -> https://www.geeksforgeeks.org/problems/majority-element-1587115620/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int majorityElement(int a[], int size)
    {
        if(size==0)
            return -1;
        else if(size==1)
            return a[0];
            
        map<int, int> num;
        for(int i=0;i<size;i++)
        {
            num[a[i]]++;
        }
        for(map<int, int>::iterator itr=num.begin();itr!=num.end();++itr)
        {
            if(itr->second>size/2)
                return itr->first;
        }
        return -1;
        
    }
};