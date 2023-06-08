#include <bits/stdc++.h> 
static bool comp(vector<int>&a,vector<int>&b){
    if(a[1]==b[1]){
        return a[2]<b[2];
    }
    return a[1]<b[1];
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        v.push_back({start[i],end[i],i+1});
    }
    vector<int>ans;
    
    sort(v.begin(),v.end(),comp);
    ans.push_back(v[0][2]);
    int limit=v[0][1];
    for(int i=1;i<n;i++){
        if(v[i][0]>limit){
            limit=v[i][1];
            ans.push_back(v[i][2]);
        }
    }
    return ans;
}