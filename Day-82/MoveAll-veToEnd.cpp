// #Question:-

// Given an unsorted array arr[] of size n having both negative and positive integers. The task is place all negative element at the end of array without 
// changing the order of positive element and negative element.

//Link -> https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int temp[n];int k=0;vector<int>V;
        for(int i=0;i<n;i++)
        {
            if(arr[i] < 0)
            {
                temp[k++]=arr[i];
            }
            else{
                V.push_back(arr[i]);
            }
        }
        
        for(int p=0;p<k;p++)
        {
            V.push_back(temp[p]);
        }
        
        for(int i=0;i<n;i++)
        {
            arr[i] =V[i];
        }
    }
};