// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/n-queen-problem0315/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool isSafe(int newR, int newC, vector<vector<int>> &boards, vector<vector<int>> &ans, int n){
        int x=newR;
        int y=newC;
        
        //checking for the row, if it's safe:-
        while(y>=0){
            if(boards[x][y] == 1){
                return false;
            }
            y--;
        }
        
        //checking for the upper-left diagonal:-
        
        x=newR;
        y=newC;
        
        while(x>=0 && y>=0){
            if(boards[x][y] == 1){
                return false;
            }
            y--;
            x--;
        }
        
        //check for the lower-left diagonal:-
        
        x=newR;
        y=newC;
        
        while(x<n && y>=0){
            if(boards[x][y] == 1){
                return false;
            }
            y--;
            x++;
        }
        return true;
    }

    void addSolu(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
        vector<int> temp;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[j][i] == 1){
                    temp.push_back(j+1);
                }
            }
        }
        ans.push_back(temp);
    }

    void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n){
        //base case:-
        if(col == n){
            addSolu(board, ans, n);
            return ;
        }
        
        //check for all posible positions in a row:-
        
        for(int row=0; row<n; row++){
            if(isSafe(row, col, board, ans, n)){
                board[row][col] = 1;
                solve(col+1, board, ans, n);
                board[row][col] = 0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>>ans;
        
        solve(0, board, ans, n);
        
        return ans;
    }
};