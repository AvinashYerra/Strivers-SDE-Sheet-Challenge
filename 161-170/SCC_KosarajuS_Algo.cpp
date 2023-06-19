#include<bits/stdc++.h>
void dfs(int node,vector<int>adj[],stack<int>&st,vector<int>&vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,st,vis);
        }
    }
    st.push(node);
}
void dfs2(int node,vector<int>&temp,vector<int>&vis,vector<int>adjT[]){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adjT[node]){
        if(!vis[it]){
            dfs2(it,temp,vis,adjT);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<int>adj[n];
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
    }
    vector<int>vis(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,st,vis);
        }
    }
    vector<int>adjT[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
        for (auto it : adj[i]) {
          adjT[it].push_back(i);
        }
    }

    vector<vector<int>>ans;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        vector<int>temp;
        if(!vis[node]){
            dfs2(node,temp,vis,adjT);
        }
         ans.push_back(temp);
    }
    return ans;

}