#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;
    
    //function to add an edge in graph
    void addEdge(int u, int v, int w){
        adj[u].push_back(make_pair(v, w));
    }

    //function to print adj matrix
    void printAdj(){
        for(auto &i: adj){
            cout << i.first << "--> " ;
            for(auto &j : i.second){
                cout << "(" << j.first << ", " << j.second << "), " ;
            }cout << endl;
        }
    }

    //function to get topological order of DAG
    void getTopoSort(int node, stack<int> &s, unordered_map<int, bool> &visited){
        visited[node] = true;

        for(auto &nbr : adj[node]){
            if(!visited[nbr.first]){
                getTopoSort(nbr.first, s, visited);
            }
        }

        s.push(node);
    }

    //function to get shortest distance
    void findShortestPath(int src, stack<int> &st, vector<int> &distance){
        distance[src] = 0;

        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(distance[top] != INT_MAX){
                for(auto &i : adj[top]){
                    if(distance[top] + i.second < distance[i.first]){
                        distance[i.first] = distance[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){

    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int n = 6; // graph has 6 vertices
    int src = 1; // taking node value 1 as source node

    stack<int> st;
    unordered_map<int, bool> visited;

    // to get the topological order of nodes
    for(int i=0; i<n;i++){
        if(!visited[i]){
            g.getTopoSort(i,st,visited); //topoSort function call
        }
    }

    vector<int> distance(n, INT_MAX); //initialising distance with INT_MAX at first

    //finding the shortest path from src for every Node
    g.findShortestPath(src, st, distance);

    //printing the distance vector
    for(int i=0; i<n; i++){
        cout << distance[i] << " " ;
    }
    return 0;
}