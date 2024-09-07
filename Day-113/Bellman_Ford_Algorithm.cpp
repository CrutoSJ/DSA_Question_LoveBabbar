// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Date-> 07/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,10e7);
        dist[S]=0;
        
        for(int i=0; i<V; i++){
            for(int j=0; j<edges.size(); j++){
                int u  = edges[j][0];
                int v  = edges[j][1];
                int wt = edges[j][2];
                
                if(dist[u] != 10e7 && wt + dist[u] < dist[v]){
                    dist[v] = wt + dist[u];
                }
            }
        }
        
        bool flag = false;
        
        for(int j=0; j<edges.size(); j++){
            int u  = edges[j][0];
            int v  = edges[j][1];
            int wt = edges[j][2];
                
            if(dist[u] != 10e7 && wt + dist[u] < dist[v]){
                flag = true;
            }
        }
        
        if (flag == false){
            return dist;
        }
        return {-1};
    }
};