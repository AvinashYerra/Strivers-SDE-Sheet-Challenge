#include <bits/stdc++.h> 
void help(int ind,int sum,int n,vector<int>&num,vector<int>&ds){
    if(ind==n){
        ds.push_back(sum);
        return;
    }
    help(ind+1,sum+num[ind],n,num,ds);
    help(ind+1,sum,n,num,ds);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ds;
    int n=num.size();
    help(0,0,n,num,ds);
    sort(ds.begin(),ds.end());
    return ds;
}