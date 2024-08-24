// #Question:-

// Link-> https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469

// Note

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int, list<pair<int,int>>> adj;
    for(auto &edge : vec){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    set<pair<int,int>> st;
    st.insert({0,source});

    while(!st.empty()){
        auto top = *(st.begin());
        st.erase(st.begin());

        int nodeDist = top.first;
        int node = top.second;

        for(auto &nbr : adj[node]){
            if(nbr.second + nodeDist < dist[nbr.first]){
                auto res = st.find({dist[nbr.first], nbr.first});
                if(res != st.end()){
                    st.erase(res);
                }
                dist[nbr.first] = nbr.second + nodeDist;
                st.insert({dist[nbr.first], nbr.first});
            }
        }
    }
    return dist;   
}