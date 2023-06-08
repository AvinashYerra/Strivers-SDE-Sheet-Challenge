#include <bits/stdc++.h> 
static bool comp(vector<int>&a,vector<int>&b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),comp);
    int n=jobs.size();
    int maxi=jobs[0][0];
    for(int i=1;i<n;i++){
        maxi=max(maxi,jobs[i][0]);
    }
    int slots[maxi+1];
    for(int i=0;i<=maxi;i++){
        slots[i]=-1;
    }
    int p=0;

    for(int i=0;i<n;i++){
        for(int j=jobs[i][0];j>0;j--){
            if(slots[j]==-1){
                slots[j]=i;
                p+=jobs[i][1];
                break;
            }
        }
    }
    return p;
}
