// #Question:-

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.


// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //element == target --> return true;
        // element < target --> row++;
        //element > target --> col--;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int rowIndex = 0;
        int colIndex = col-1;
        
        while(rowIndex<row && colIndex>=0){
            
            int s = matrix[rowIndex][colIndex];
            
            if(s == target ){
                return true;
            }
            
            else if(s < target){
                rowIndex++;
            }
            
            else{
                colIndex--;
            }  
        }
        return false;
    }
};