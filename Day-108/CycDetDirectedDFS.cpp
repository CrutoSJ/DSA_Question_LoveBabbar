// #Question:-

// Link-> https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>

bool isCycle(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, 
            unordered_map<int, bool> &dfsVis, int node, int parent){
    visited[node] = true;
    dfsVis[node] = true;

    for(auto &nbr : adj[node]){
        if(!visited[nbr]){
        bool ans = isCycle(adj, visited, dfsVis, nbr, node);
        if(ans){
            return true;
        }
        } else if(dfsVis[nbr] == true){
        return true;
        }
    }
    dfsVis[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVis;

    for(auto &edge : edges){
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
    }

    for(int i=1; i<n; i++){
        if(!visited[i]){
        bool ans = isCycle(adj, visited, dfsVis, i, -1);
            if(ans){
                return true;
            }
        }
    }
    return false;
}