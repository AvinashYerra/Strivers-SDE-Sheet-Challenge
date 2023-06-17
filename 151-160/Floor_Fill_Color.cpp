#include<bits/stdc++.h>
void dfs(int row,int col,vector<vector<int>> &image,vector<vector<int>>&ans,int ic,int nc,int delr[],
int delc[]){
    ans[row][col]=nc;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delr[i];
        int ncol=col+delc[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==ic && ans[nrow][ncol]!=nc){
            dfs(nrow,ncol,image,ans,ic,nc,delr,delc);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int ic=image[x][y];
    vector<vector<int>>ans=image;
    int delr[]={-1,0,1,0};
    int delc[]={0,1,0,-1};
    dfs(x,y,image,ans,ic,newColor,delr,delc);
    return ans;
}