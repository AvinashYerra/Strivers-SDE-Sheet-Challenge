#include <bits/stdc++.h> 
bool help(int ind,int k,vector<int>&arr,vector<vector<int>>&dp){
    if(k==0) return true;
    if(ind==0){
        return (arr[0]==k);
    }
    if(dp[ind][k]!=-1) return dp[ind][k];
    bool ntake=help(ind-1,k,arr,dp);
    bool take=false;
    if(arr[ind]<=k){
        take=help(ind-1,k-arr[ind],arr,dp);
    }
    return dp[ind][k]=(take||ntake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return help(n-1,k,arr,dp);
}