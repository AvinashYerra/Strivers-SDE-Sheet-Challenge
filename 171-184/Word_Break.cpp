#include <bits/stdc++.h> 
bool help(int ind,string &s,unordered_map<string,int>&mp,int n,vector<int>&dp){
  if(ind>=s.size()) return 1;
  if(dp[ind]!=-1) return dp[ind];
  for(int i=ind;i<s.size();i++){
    if(mp.find(s.substr(ind,i-ind+1))!=mp.end()){
      if(help(i+1,s,mp,n,dp)){
        return dp[ind]=true;
      }
    }
  }
  return dp[ind]=false;
  
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    int x=target.size();
    vector<int>dp(x+1,-1);
    return help(0,target,mp,n,dp);
    
}