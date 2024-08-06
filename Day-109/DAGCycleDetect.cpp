// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;



class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V);
        
        for(int i=0; i<V; i++){
            for(auto &j : adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            cnt++;
            
            for(auto &nbr : adj[front]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        
        return cnt != V;
    }
};