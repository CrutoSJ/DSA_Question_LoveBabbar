// #Question:- 

// Link-> https://www.naukri.com/code360/problems/minimum-spanning-tree_631769

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

class cmp{
  public:
    bool operator()(vector<int> &a, vector<int> &b){
      return a[2] < b[2];
    }
};

void makeSet(vector<int> &parent, vector<int> &rank, int n){
  for(int i=0; i<n; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

int findParent(vector<int> &parent, int node){
  if(parent[node] == node){
    return node;
  }

  return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
   u = findParent(parent, u);
   v = findParent(parent, v);

   if(rank[u] < rank[v]){
      parent[u] = v;
   } else if(rank[v] < rank[u]){
      parent[v] = u;
   } else{
      parent[u] = v;
      rank[v]++;
   }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  vector<int> parent(n);
  vector<int>rank(n);
  makeSet(parent, rank, n);

  sort(edges.begin(), edges.end(), cmp());
  int minWeight = 0;

  for(int i=0; i<edges.size(); i++){
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int wt = edges[i][2];

    if(u!=v){
      minWeight += wt;
      unionSet(u, v, parent, rank);
    }
  }
  return minWeight;
}