// #Question:-

// Link-> https://www.geeksforgeeks.org/problems/topological-sort/1

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
	    
	    for(int i=0; i<V; i++){
	        for(auto &j : adj[i]){
	            indegree[j]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    
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
};