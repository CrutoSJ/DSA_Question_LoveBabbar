// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/articulation-point-1/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    if(a<b){
        return a;
    } return b;
}

void dfs(int node, int parent, int timer, vector<int> &disc, vector<int> &low, 
            unordered_map<int, bool> &vis, vector<int> &arPnt, 
            unordered_map<int, list<int>> &adj){
    
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int childCnt = 0;

    for(auto &nbr : adj[node]){
        if(nbr == parent){
            continue;
        } else if(!vis[nbr]){
            dfs(nbr, node, timer, disc, low, vis, arPnt, adj);
            low[node] = min(low[node], low[nbr]);
            if(low[nbr] >= disc[node] && parent != -1){
                arPnt[node] = 1;
            }
            childCnt++;
        } else{
            low[node] = min(low[node], disc[nbr]);
        }
    }
    
    if(parent == -1 && childCnt>1){
        arPnt[node] = 1;
    }

}

int main(){

    int n = 5;
    int e = 5;

    vector<vector<int>> edges;
    edges.push_back({0,3});
    edges.push_back({3,4});
    edges.push_back({0,4});
    edges.push_back({0,1});
    edges.push_back({1,2});

    unordered_map<int, list<int>> adj;
    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    unordered_map<int, bool> vis;

    vector<int> arPnt(n, 0);

    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, parent, timer, disc, low, vis, arPnt, adj);
        }
    }

    cout << "Articulation Points are: ";
    for(int i=0; i<arPnt.size(); i++){
        if(arPnt[i] == 1){
            cout << i << " ";
        }
    } cout << endl;

    return 0;
}