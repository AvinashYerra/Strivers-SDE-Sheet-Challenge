#include<bits/stdc++.h>
static bool comp(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>>v;
    int n=start.size();
    for(int i=0;i<n;i++){
        v.push_back({start[i],finish[i]});
    }
    sort(v.begin(),v.end(),comp);
    int ans=0;
    int limit=v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first>=limit){
            limit=v[i].second;
            ans++;
        }
    }
    return ans+1;
}