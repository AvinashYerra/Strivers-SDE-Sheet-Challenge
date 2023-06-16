#include<bits/stdc++.h>
long help(int ind,int value,int *denominations,vector<vector<long>>&dp){
    if(ind==0) {
        return (value%denominations[ind]==0) ;
    }
    if(dp[ind][value]!=-1) return dp[ind][value];
    long ntake=help(ind-1,value,denominations,dp);
    long take=0;
    if(denominations[ind]<=value){
        take=help(ind,value-denominations[ind],denominations,dp);
    }
    return dp[ind][value]=take+ntake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>>dp(n+1,vector<long>(value+1,-1));
    return help(n-1,value,denominations,dp);

}