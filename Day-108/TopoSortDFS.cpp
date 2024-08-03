// #Question:-

// Link-> https://www.naukri.com/code360/problems/topological-sort_982938

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

void topoSort(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, stack<int> &s){
    visited[node] = true;

    for(auto &nbr : adj[node]){
        if(!visited[nbr]){
            topoSort(nbr, adj, visited, s);
        }
    }

    s.push(node);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;
    for(auto &edge: edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            topoSort(i, adj, visited, s);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}