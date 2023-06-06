#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n=arr.size();
    int ans=0;
    int xr=0;
    map<int,int>mp;
    mp[xr]++;
    for(int i=0;i<n;i++){
        xr^=arr[i];
        int y=xr^x;
        ans+=mp[y];
        mp[xr]++;
    }
    return ans;
}