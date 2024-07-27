// #Question:-

// Link-> https://www.naukri.com/code360/problems/rat-in-a-maze_1215030

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
bool isSafe(int newX, int newY, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n){
    if((newX >= 0 && newX <n) && (newY >= 0 && newY < n) && visited[newX][newY] != 1 && arr[newX][newY] == 1){
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, vector<string> &ans, vector<vector<bool>> &visited,
            int n, string temp){
    if(x==n-1 && y ==n-1){
        ans.push_back(temp);
    }

    //Down, Left, Right, Up:-

    visited[x][y] = 1;
    //1st check for Down:-
    if(isSafe(x+1, y, visited, arr, n)){
        solve(x+1, y, arr, ans, visited, n, temp+'D');
    } 

    //2nd Left:-
    if(isSafe(x, y-1, visited, arr, n)){
        solve(x, y-1, arr, ans, visited, n, temp+'L');
    }

    //3rd Right:-
    if(isSafe(x, y+1, visited, arr, n)){
        solve(x, y+1, arr, ans, visited, n, temp+'R');
    }

    //4th Up:-
    if(isSafe(x-1, y, visited, arr, n)){
        solve(x-1, y, arr, ans, visited, n, temp+'U');
    }

    visited[x][y] = 0;   
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {

    vector<string>ans;
    
    if(arr[0][0] == 0) return ans;

    string temp="";
    vector<vector<bool>> visited(n, vector<bool>(n,false));

    solve(0, 0, arr, ans, visited, n, temp);

    return ans;
}