#include <bits/stdc++.h> 
int help(int i,int j,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;
	if(i==0 && j==0) return 1;
	if(dp[i][j]!=-1) return dp[i][j];
	int up=help(i-1,j,dp);
	int right=help(i,j-1,dp);
	return dp[i][j]=up+right;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m,vector<int>(n,-1));
	return help(m-1,n-1,dp);
}