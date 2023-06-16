#include <bits/stdc++.h> 
bool ispalin(string str){
   int n=str.size();
   for(int i=0;i<n/2;i++){
       if(str[i]!=str[n-i-1]) return false;
   }
   return true;
}
int help(int i,string &str,int n,vector<int>&dp){
    if(i==n) return 0;
    int mini=INT_MAX;
    if(dp[i]!=-1) return dp[i];
    for(int j=i;j<=n-1;j++){
        if(ispalin(str.substr(i,j-i+1))){
            int temp=1+help(j+1,str,n,dp);
            mini=min(temp,mini);a
        }
    }
    return dp[i]=mini;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
    vector<int>dp(n,-1);
    return help(0,str,n,dp)-1;
}
