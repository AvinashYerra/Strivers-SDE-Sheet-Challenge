#include <bits/stdc++.h>
void func(vector<vector<int>>&ans,vector<vector<int>>&vis){
  vector<int>temp;
  int n=vis.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp.push_back(vis[i][j]);
    }
  }
  ans.push_back(temp);
} 
void help(int i,int j,vector<vector<int> > &maze,int n,vector<vector<int>>&vis,vector<vector<int>>&ans){
  if(i==n-1 && j==n-1){
    func(ans,vis);
    return ;
  }
  if(i+1<n && vis[i+1][j]==0 && maze[i+1][j]==1){
    vis[i+1][j]=1;
    help(i+1,j,maze,n,vis,ans);
    vis[i+1][j]=0;
  }
  if(j-1>=0 && vis[i][j-1]==0 && maze[i][j-1]==1){
    vis[i][j-1]=1;
    help(i,j-1,maze,n,vis,ans);
    vis[i][j-1]=0;
  }
   if(j+1<n && vis[i][j+1]==0 && maze[i][j+1]==1){
    vis[i][j+1]=1;
    help(i,j+1,maze,n,vis,ans);
    vis[i][j+1]=0;
  }
   if(i-1>=0 && vis[i-1][j]==0 && maze[i-1][j]==1){
    vis[i-1][j]=1;
    help(i-1,j,maze,n,vis,ans);
    vis[i-1][j]=0;
  }

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>>vis(n,vector<int>(n,0));
  vector<vector<int>>ans;
  vector<int>ds;
  if (maze[0][0] == 1) {
    vis[0][0]=1;
    help(0, 0, maze, n, vis, ans);
  }
  return ans;
}