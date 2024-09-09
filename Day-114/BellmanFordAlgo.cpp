// #Question:-

// Link-> https://www.naukri.com/code360/problems/bellmon-ford_2041977

// Date-> 09/09/24

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 10e7);
    dist[src] = 0;

    for(int i=1; i<=n-1; i++){
        for(int j=0; j<m; j++){
            int u  = edges[j][0];
            int v  = edges[j][1];
            int wt = edges[j][2];

            if((dist[u] + wt < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}