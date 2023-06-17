#include<bits/stdc++.h>
bool check(int src,vector<int>adj[],vector<int>&vis){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i,node});
            }else if(i!=parent){
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);

    }
    string ans="Yes";
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(check(i,adj,vis)){
                return ans;
            }
        }
    }
    ans="No";
    return ans;
}
