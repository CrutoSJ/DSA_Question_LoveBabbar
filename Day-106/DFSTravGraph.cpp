// #Question:-

// Link-> https://www.naukri.com/code360/problems/dfs-traversal_630462

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, int node, vector<int> &temp){
    temp.push_back(node);
    visited[node] = true;

    for(auto &nbr : adj[node]){
        if(!visited[nbr]){
            dfs(adj, visited, nbr, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int>temp;
            dfs(adj, visited, i, temp);
            ans.push_back(temp);
        }
    }

    return ans;
}