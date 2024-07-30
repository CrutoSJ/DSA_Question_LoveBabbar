// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isCycle(vector<int> adj[], int node, unordered_map<int, bool> &visited){
        unordered_map<int, int> parent;
        parent[node] = -1;
        queue<int>q;
        q.push(node);
        visited[node] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto &nbr: adj[front]){
                if(visited[nbr] == true && nbr != parent[front]){
                    return true;
                }
                
                else if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = front;
                }
            }
        }
        return false;
    }
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, bool>visited;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = isCycle(adj, i, visited);
                if(ans == true){
                    return 1;
                }
            }
        }
        return 0;
    }
};