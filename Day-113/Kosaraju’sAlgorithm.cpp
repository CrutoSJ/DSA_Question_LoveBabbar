// #Question:-

// Link-> https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, stack<int> &st, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    visited[node] = true;

    for(auto &nbr : adj[node]){
        if(!visited[nbr]){
            dfs(nbr, st, visited, adj);
        }
    }
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &revAdj){
    visited[node] = true;

    for(auto &nbr : revAdj[node]){
        if(!visited[nbr]){
            revDfs(nbr, visited, revAdj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    stack<int>st;
    unordered_map<int, bool> visited;

    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, st, visited, adj);
        }
    }

    unordered_map<int, list<int>> revAdj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        revAdj[v].push_back(u);
    }

    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!visited[top]){
            count++;
            revDfs(top, visited, revAdj);
        }

    }

    return count;

}