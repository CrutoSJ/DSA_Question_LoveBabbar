// #Question:-

// Implement a graph using adj list, perform adding edge & printing graph"

// #Solution:-

#include<bits/stdc++.h>
using namespace std;
template <typename T>

class graph{
    public:
        unordered_map<T, list<T>>adj;

        void insertEdge(T u, T v, bool direction){
            //direction = 0 -> undirected;
            //direction = 1 -> directed;

            adj[u].push_back(v);

            if(direction == 0){
                adj[v].push_back(u);
            }
        }

        void printAdj(){
            for(auto &i : adj){
                cout << i.first << " -> ";
                for(auto &j : i.second){
                    cout << j << ", ";
                } cout << endl;
            }
        }
};

int main(){

    int n;
    cout << "Enter the no. of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the no. of edges: ";
    cin >> m;

    graph<int> g;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        g.insertEdge(u, v, 0);
    }

    g.printAdj();

    return 0;
}