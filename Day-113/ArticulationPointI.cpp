// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/articulation-point-1/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int timer, vector<int> &key, vector<int> &low, unordered_map<int, bool> &visited, 
                vector<int>adj[], vector<int> &artPnt, int node, int parent){
        visited[node] = true;
        key[node] = low[node] = timer++;
        
        int childCnt = 0;
        
        for(auto &nbr : adj[node]){
            if(nbr == parent){
                continue;
            } else if(!visited[nbr]) { 
                dfs(timer, key, low, visited, adj, artPnt, nbr, node);
                low[node] = min(low[node] , low[nbr]);
                if(low[nbr] >= key[node] && parent!= -1){
                    artPnt[node] = 1; 
                }
                childCnt++;
            } else{
                low[node] = min(low[node], key[nbr]);
            }
        }
        
        if(parent == -1 && childCnt>1){
            artPnt[node] = 1;
        }
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        int timer = 0;
        vector<int> key(V,-1);
        vector<int> low(V,-1);
        int parent = -1;
        unordered_map<int, bool> visited;
        
        vector<int> artPnt(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(timer, key, low, visited, adj, artPnt, i, parent);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<artPnt.size(); i++){
            if(artPnt[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0){
            return {-1};
        }
        
        return ans;
    }
};