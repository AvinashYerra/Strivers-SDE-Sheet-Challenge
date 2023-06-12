#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    vector<vector<int>>vis(n,vector<int>(m));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }else{
                vis[i][j]=0;
            }
        }
    }
    int maxi=0;
    int delr[]={-1,0,1,0};
    int delc[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int time=q.front().second;
        q.pop();
        maxi=max(maxi,time);
        for(int k=0;k<4;k++){
            int nr=row+delr[k];
            int nc=col+delc[k];
            if(nr>=0 && nr<n &&nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
                q.push({{nr,nc},time+1});
                vis[nr][nc]=2;
                
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]!=2){
                return -1;
            }
        }
    }
    return maxi;
}