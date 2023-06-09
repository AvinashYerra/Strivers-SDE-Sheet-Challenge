#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    vector<long>mxl(n);
    vector<long>mxr(n);
    mxl[0]=arr[0];
    for(int i=1;i<n;i++){
        mxl[i]=max(mxl[i-1],arr[i]);
    }
    mxr[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        mxr[i]=max(mxr[i+1],arr[i]);
    }
    long ans=0;
    for(int i=0;i<n;i++){
        ans+=(min(mxl[i],mxr[i])-arr[i]);
    }
    return ans;
}