#include <bits/stdc++.h> 
int help(int i,int j,vector<int>&arr,int N,vector<vector<int>>&dp){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp=help(i,k,arr,N,dp)+help(k+1,j,arr,N,dp)+arr[i-1]*arr[k]*arr[j];
        if(temp<mn){
            mn=temp;
        }
    }
    return dp[i][j]=mn;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N,vector<int>(N,-1));
    int i=1;
    int j=N-1;
    return help(i,j,arr,N,dp);
}