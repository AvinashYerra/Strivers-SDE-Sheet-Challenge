#include <bits/stdc++.h> 
bool issafe(int node,vector<vector<int>>&mat,int n,int m,vector<int>&color,int col){
    for(int k=0;k<n;k++){
        if(node!=k && mat[node][k]!=0 && color[k]==col){
            return false;
        }
    }
    return true;
}
bool solve(int node,vector<vector<int>>&mat,int n,int m,vector<int>&color){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(issafe(node,mat,n,m,color,i)){
            color[node]=i;
           if(solve(node+1,mat,n,m,color)) return true;
            color[node]=0;
        }  
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n=mat.size();
    vector<int>color(n,0);
    if(solve(0,mat,n,m,color)) return "YES";
    return "NO";
}