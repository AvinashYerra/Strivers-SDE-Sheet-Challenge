#include<bits/stdc++.h>
int help(int e,int f,vector<vector<int>>&dp){
    if(f==0 || f==1 || e==1) return dp[e][f]=f;
    if(dp[e][f]!=-1) return dp[e][f];
    int ans=INT_MAX;
    int start=1,end=f;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(dp[e-1][mid-1]==-1){
            dp[e-1][mid-1]=help(e-1,mid-1,dp);
        }
        int x=dp[e-1][mid-1];
        if(dp[e][f-mid]==-1){
            dp[e][f-mid]=help(e,f-mid,dp);
        }
        int y=dp[e][f-mid];
        ans=min(ans,1+max(x,y));
        if(x<y){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return dp[e][f]=ans;
}
int cutLogs(int k, int n)
{
    // Write your code here.
    vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
    return help(k,n,dp);
}
