// #Question:-

// Link-> https://www.naukri.com/code360/problems/prim-s-mst_1095633

// #SOlution:-

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;

    //preparing the adj list:-
    for(auto &i : g){
        int u = i.first.first;
        int v = i.first.second;
        int wt = i.second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    //creation of 3 arrays :-
    vector<int> key(n+1, INT_MAX);
    vector<int> vis(n+1, false);
    vector<int> parent(n+1, -1);

    key[1] = 0;
    parent[1] = -1;
    int sIdx;

    for(int i=1; i<n; i++){

        int mini = INT_MAX;
        //finding the min value in the vector
        for(int i=1; i<=n; i++){
            if(vis[i] == false && key[i] < mini){
                sIdx = i;
                mini = key[i];
            }
        }
        //marking the vis that this node is taken
        vis[sIdx] = true;

        //traverse on the adj for finding min dis to corresponding nodes
        for(auto &nbr : adj[sIdx]){
            if(vis[nbr.first] == false && nbr.second < key[nbr.first]){
                key[nbr.first] = nbr.second;
                parent[nbr.first] = sIdx;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for(int i=2; i<=n; i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;
}
