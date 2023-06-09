#include<bits/stdc++.h>
int smallmid(vector<int>&a,int mid){
    int ind=upper_bound(a.begin(),a.end(),mid)-a.begin();
    return ind;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    int low=1;
    int high=1e9;

    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=smallmid(matrix[i],mid);
        }
        if(cnt<=n*m/2) low=mid+1;
        else high=mid-1;
    }
    return low;

}