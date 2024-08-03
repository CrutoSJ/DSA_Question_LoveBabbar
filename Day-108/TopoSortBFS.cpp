// #Question:-

// Link-> https://www.naukri.com/code360/problems/topological-sort_982938

// #Solution:-

#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>> adj;

    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    //find indegree:-
    vector<int> indegree(v);

    for(auto &i : adj){
        for(auto &j : i.second){
            indegree[j]++;
        }
    }

    //normal bfs with modification
    vector<int> ans;
    queue<int>q;

    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto &nbr : adj[front]){
            indegree[nbr]--;
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }

    return ans;

}