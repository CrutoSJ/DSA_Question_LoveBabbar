// #Question:-

// Link-> https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>

bool isCycle(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, int node, int parent){
    visited[node] = true;

    for(auto &nbr : adj[node]){
        if(!visited[nbr]){
            bool ans = isCycle(adj, visited, nbr, node);
            if(ans){
                return true;
            }
        } else if(parent != nbr){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<n; i++){
        if(!visited[i]){
            bool ans = isCycle(adj, visited, i, -1);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}
