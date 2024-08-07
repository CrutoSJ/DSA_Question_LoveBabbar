// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void getTopoSort(stack<int> &s, unordered_map<int, list<pair<int, int>>> &adj,  unordered_map<int, bool>& visited, int node){
        visited[node] = true;
        
        for(auto &nbr : adj[node]){
            if(!visited[nbr.first]){
                getTopoSort(s, adj, visited, nbr.first);
            }
        }
        
        s.push(node);
    }
    
    void getShortestDist(stack<int> &s, vector<int>&distance, unordered_map<int, list<pair<int, int>>>adj){
        distance[0] = 0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            if(distance[top] != INT_MAX){
                for(auto &i : adj[top]){
                    if(distance[top] + i.second < distance[i.first]){
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
    
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int, list<pair<int, int>>>adj;
        
        //making the adjancency list
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back(make_pair(v,wt));
        }
        
        //get topological sort order to start from a node
        stack<int> s;
        unordered_map<int, bool> visited;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                getTopoSort(s, adj, visited, i);
            }
        }
        
        //make a initial distance vector 
        vector<int> distance(N, INT_MAX);
        
        //update the disatnce vector accordingly
        getShortestDist(s, distance, adj);
        
        //converting the infinity to -1, as demanded in the question
        for(int i=0; i<N; i++){
            if(distance[i] == INT_MAX){
                distance[i] = -1;
            }
        }
        
        return distance;
        
    }
};