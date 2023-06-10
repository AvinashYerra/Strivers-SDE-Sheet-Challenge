#include <bits/stdc++.h> 
#define ppi pair<int,pair<int,int>>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
    for(int i=0;i<k;i++){
        pq.push({kArrays[i][0],{i,0}});
    }
    vector<int>ans;
    while(pq.size()>0){
        ppi req=pq.top();
        pq.pop();
        int value=req.first;
        int li=req.second.first;
        int di=req.second.second;
        ans.push_back(value);
        if(di+1<kArrays[li].size()){
            pq.push({kArrays[li][di+1],{li,di+1}});
        }
    }
    return ans;
}
