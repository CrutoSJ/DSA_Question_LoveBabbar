// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        
        distance[0] = 0;
        parent[0] = -1;
        
        int idx=-1;
        
        for(int i=0; i<V; i++){
            int mini = INT_MAX;
            for(int j=0; j<V; j++){
                if(visited[j] == false && distance[j] < mini){
                    idx = j;
                    mini = distance[j];
                }
            }
            
            visited[idx] = true;
            
            for(auto &nbr : adj[idx]){
                if((visited[nbr[0]] == false) && nbr[1] < distance[nbr[0]]){
                    distance[nbr[0]] = nbr[1];
                    parent[nbr[0]] = idx;
                }
            }
        }
        
        int cost = 0;
        for(int i=0; i<V; i++){
            cost += distance[i];
        }
        
        return cost;
    }
};