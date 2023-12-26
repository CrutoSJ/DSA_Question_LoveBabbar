// #Question:-

// Given an m x n matrix, return all elements of the matrix in spiral order.

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int>ans;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int elements = row*col;
        
        int firstColIndex = 0;
        int firstRowIndex = 0;
        int lastColIndex = col-1;
        int lastRowIndex = row-1;
        
        while(count<elements){
            
            //for first Row:-
            for(int index=firstColIndex; count<elements && index<=lastColIndex; index++){
                ans.push_back(matrix[firstRowIndex][index]);
                count++;
            }
            
            firstRowIndex++;
            
            //for last coloumn:-
            for(int index=firstRowIndex; count<elements && index<=lastRowIndex; index++){
                ans.push_back(matrix[index][lastColIndex]);
                count++;
            }
            
            lastColIndex--;
            
            //for last Row:-
            for(int index=lastColIndex; count<elements && index>=firstColIndex; index--){
                ans.push_back(matrix[lastRowIndex][index]);
                count++;
            }
            
            lastRowIndex--;
            
            //for first Col:-
            for(int index=lastRowIndex; count<elements && index>=firstRowIndex; index--){
                ans.push_back(matrix[index][firstColIndex]);
                count++;
            }
            
            firstColIndex++;
        }
        
        return ans;
    }
};