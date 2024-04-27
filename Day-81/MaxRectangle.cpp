// #Question:-

// Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

//Attempt - 2

// #Solution:-

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
private:
    vector<int>nextSmallerElement(int* arr, int n){
        stack<int>s;
        s.push(-1);
        
        vector<int>ans(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int>prevSmallerElement(int* arr, int n){
        stack<int>s;
        s.push(-1);
        
        vector<int>ans(n);
        
        for(int i=0; i<n; i++){
            int curr = arr[i];
            
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int* heights, int n) {
        //int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        
        for(int i=0; i<n; i++){
            int l = heights[i];
            
            if(next[i] == -1){
                next[i] = n;
            }
            
            int b = next[i] - prev[i] - 1;
            
            int newArea = l*b;
            area = max(area, newArea);
        }
        
        return area;
    }
    
public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int area = largestRectangleArea(M[0],m);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] != 0){
                    M[i][j] = M[i][j] + M[i-1][j];
                }
                
                else{
                    M[i][j] = 0;
                }
            }
            
            area = max(area, largestRectangleArea(M[i],m));
        }
        
        return area;
    }
};