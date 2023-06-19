#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<pair<int,int>>adj[vertices];
    for(auto it:vec){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>dist(vertices,INT_MAX);
    set<pair<int,int>>st;
    dist[source]=0;
   st.insert({0,source});
    while(!st.empty()){
      auto it=*(st.begin());
      int node=it.second;
      int dis=it.first;
      st.erase(it);
      for(auto i:adj[node]){
          int edgw=i.second;
          int adjnode=i.first;
          if(dis+edgw<dist[adjnode]){
              dist[adjnode]=dis+edgw;
              st.insert({dist[adjnode],adjnode});
          }
      }

    }
    return dist;
}
