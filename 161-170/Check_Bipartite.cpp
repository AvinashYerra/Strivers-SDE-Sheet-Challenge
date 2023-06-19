#include<bits/stdc++.h>
bool check(int start,vector<int>adj[],vector<int>&color){
	color[start]=0;
	queue<int>q;
	q.push(start);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto it:adj[node]){
			if(color[it]==-1){
				color[it]=!color[node];
				q.push(it);
			}else if(color[it]==color[node]){
				return false;
			}
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int v=edges.size();
	vector<int>adj[v];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if(edges[i][j]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	vector<int>color(v,-1);
	for(int i=0;i<v;i++){
		if(color[i]==-1){
			if(check(i,adj,color)==false){
				return false;
			}
		}
	}
	return true;
}