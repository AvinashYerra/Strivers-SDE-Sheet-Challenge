void dfs(int node,vector<int>&temp,vector<int>&vis,vector<int>adj[]){
    vis[node]=1;
    temp.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,temp,vis,adj);
            vis[it]=1;
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int>adj[V];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<vector<int>>ans;
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int>temp;
            dfs(i,temp,vis,adj);
            ans.push_back(temp);
        }
    }
    return ans;
}