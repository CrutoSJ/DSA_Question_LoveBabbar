// #Question:-

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Link -> https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool possible(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> visited){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited [x][y] == 0 && m[x][y] == 1 ){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> m, int n, vector<vector<int>> visited, string path, vector<string>& ans,
               int x, int y){
                   if(x == n-1 && y == n-1){
                       ans.push_back(path);
                       return ; 
                   }
                   
                   visited[x][y]=1;
                   
                   //movements :- Down,Up,Right,Left
                   
                   //Down:-
                   int newx = x+1;
                   int newy = y;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('D');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   //Left:-
                   newx = x;
                   newy = y-1;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('L');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   //Up:-
                   newx = x-1;
                   newy = y;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('U');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   //Right:-
                   newx = x;
                   newy = y+1;
                   if(possible(newx, newy, m, n, visited)){
                       path.push_back('R');
                       solve(m, n, visited, path, ans, newx, newy);
                       path.pop_back();
                   }
                   
                   visited[x][y]=0;
               }
    
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m [0] [0] == 0){
            return ans;
        }
        
        int xind = 0;
        int yind = 0;
        
        vector<vector<int>> visited = m;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited [i][j] = 0;
            }
        }
        
        string path = "";
        
        solve(m, n, visited, path, ans, xind, yind);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};