// #Question:-

// Link-> https://leetcode.com/problems/n-queens/description/

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, bool>rowCheck;
    unordered_map<int, bool>upLeftDia;
    unordered_map<int, bool>loLeftDia;

    bool isSafe(int row, int col, vector<string> &board, vector<vector<string>> &ans, int n){
        /*cehck for each of the possible attacks:-
        1) row attack
        2) upper diagonal attack
        3) lower diagonal attack    
        */

        // checking for row:-
        if(rowCheck[row] == true){
            return false;
        }

        //checking for upLeftDia:-
        if(upLeftDia[n-1+col-row] == true){
            return false;
        }

        //checking for loLeftDia:-
        if(loLeftDia[row+col] == true){
            return false;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return ;
        }

        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, ans, n)){

                board[row][col] = 'Q'; // placing the queen

                //marking the presence of queen 
                rowCheck[row] = true;
                upLeftDia[n-1+col-row] = true;
                loLeftDia[row+col] = true;

                solve(col+1, board, ans, n);

                //Backtracking and removing the presence
                rowCheck[row] = false;
                upLeftDia[n-1+col-row] = false;
                loLeftDia[row+col] = false;

                board[row][col] = '.'; // removal of queen from the board
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n,'.'));
        vector<vector<string>> ans;
        solve(0, board, ans, n);
        return ans;
    }
};