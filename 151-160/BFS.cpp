#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>adj[vertex];
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<vertex;i++) sort(adj[i].begin(),adj[i].end());
    vector<int>ans;
    vector<int>vis(vertex,0);
    vis[0]=1;
    queue<int>q;
    q.push(0);
    for(int i=0;i<vertex;i++){
        if(!vis[i]){
            q.push(i);
        }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        ans.push_back(x);
        for(auto it:adj[x]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    }
    return ans;
}