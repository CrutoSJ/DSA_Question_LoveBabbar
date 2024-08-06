// #Question:-

// Link-> https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	unordered_map<int, list<int>> adj;

	//making adj matrix from edges
	for(auto &edge : edges){
		int u = edge.first;
		int v = edge.second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//performing the BFS to get all parents for nodes

	unordered_map<int, bool> visited;
	vector<int> parent(n+1);

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto &nbr : adj[front]){
			if(!visited[nbr]){
				visited[nbr] = true;
				parent[nbr] = front;
				q.push(nbr);
			}
		}
	}

	//now we need to find path from parent
	vector<int> path;
	path.push_back(t);

	int currNode = t;
	while(currNode != s){
		currNode = parent[currNode];
		path.push_back(currNode);
	}

	//reverse as we went from target --> parent & want parent --> target
	reverse(path.begin(), path.end());

	return path;
	
}
