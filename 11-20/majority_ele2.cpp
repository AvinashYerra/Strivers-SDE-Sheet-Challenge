#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n=arr.size();
    vector<int>ans;
    int cnt1=0;
    int cnt2=0;
    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;i++){
       if(arr[i]==ans1){
           cnt1++;
       }else if(arr[i]==ans2){
           cnt2++;
       }else if(cnt1==0){
           cnt1=1;
           ans1=arr[i];
       }else if(cnt2==0){
           cnt2=1;
           ans2=arr[i];
       }else{
           cnt1--;
           cnt2--;
       }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==ans1){
            cnt1++;
        }
        else if(arr[i]==ans2){
            cnt2++;
        }
    }
    if(cnt1>n/3) ans.push_back(ans1);
    if(cnt2>n/3) ans.push_back(ans2);
    return ans;
}