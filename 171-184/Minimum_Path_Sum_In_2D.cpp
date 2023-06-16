#include <bits/stdc++.h> 
int help(int i, int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[0][0];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int x=help(i-1,j,grid,dp);
    int y=help(i,j-1,grid,dp);
    return dp[i][j]=min(x,y)+grid[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return help(n-1,m-1,grid,dp);
}