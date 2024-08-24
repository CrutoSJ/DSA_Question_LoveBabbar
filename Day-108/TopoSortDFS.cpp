// #Question:-

// Link-> https://www.naukri.com/code360/problems/topological-sort_982938

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

void topoSort(int node, vector<vector<int>>&adj, vector<bool> &visited, stack<int> &st){
    visited[node] = true;

    for(auto &nbr : adj[node]){
        if(!visited[nbr]){
            topoSort(nbr,adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(auto &edge : edges){
        int x = edge[0];
        int y = edge[1];

        adj[x].push_back(y);
    }

    vector<bool> visited(v,false);
    stack<int> st;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            topoSort(i, adj, visited, st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}