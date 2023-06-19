#include<bits/stdc++.h>
void dfs(int row,int col,int** arr,vector<vector<int>>&vis,int n,int m){
   
   vis[row][col]=1;
   int delr[]={-1,-1,0,1,1,1,0,-1};
   int delc[]={0,1,1,1,0,-1,-1,-1};
   for(int i=0;i<8;i++){
      int nrow=row+delr[i];
      int ncol=col+delc[i];
      if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && arr[nrow][ncol]==1 && vis[nrow][ncol]==0){
         dfs(nrow,ncol,arr,vis,n,m);
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int ans=0;
   vector<vector<int>>vis(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(arr[i][j]==1){
           if (!vis[i][j]) {
             dfs(i, j, arr, vis, n, m);
             ans++;
           }
         }
      }
   }
   return ans;
}
