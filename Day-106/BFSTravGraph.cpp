// #Question:-

// Link-> https://www.naukri.com/code360/problems/bfs-in-graph_973002

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node){
    queue<int>q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto nbr : adj[frontNode]){
            if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
            }
        } 
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &edges){
    vector<int>ans;
    unordered_map<int, bool>visited;
    
    bfs(edges, ans, visited,0);

    return ans;
}