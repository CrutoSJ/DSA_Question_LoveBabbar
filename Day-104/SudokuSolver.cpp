// #Question:-

// Link-> https://www.naukri.com/code360/problems/sudoku-solver_699919

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int val){
    /*perform 3 checks:-
    1) for that row
    2) for that col
    3) for that 3*3 matrix
    */

    for(int i=0; i<9; i++){
        //checking for row:-
        if(sudoku[i][col] == val){
            return false;
        }

        //checking for col:-
        if(sudoku[row][i] == val){
            return false;
        }

        //checking for that 3*3 matrix:-
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3] == val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &sudoku){
    for(int row=0; row<9; row++){
        for(int col=0; col<9; col++){
            if(sudoku[row][col] == 0){

                //check for the valid num that could be possible
                for(int val=1; val<=9; val++){
                    if(isSafe(row, col, sudoku, val)){
                        sudoku[row][col] = val;
                        bool isNextPoss = solve(sudoku);
                        if(isNextPoss == true){
                            return true;
                        } 
                        else{
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}