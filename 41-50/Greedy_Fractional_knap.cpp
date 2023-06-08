#include <bits/stdc++.h> 
static bool comp(pair<int,int>&a,pair<int,int>&b){
    double x=(double)a.second/(double)a.first;
    double y=(double)b.second/(double)b.first;
    return x>y;

}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);
    int curr=0;
    double final=0;
    for(int i=0;i<n;i++){
        if(curr+items[i].first <= w){
            final+=items[i].second;
            curr+=items[i].first;
        }else{
            int remain=w-curr;
            final+=(items[i].second/(double)items[i].first)*(double)remain;
            break;
        }
    }
    return final;

}