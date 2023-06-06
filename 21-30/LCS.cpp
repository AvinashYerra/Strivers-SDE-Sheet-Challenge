#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int>s;
    for(auto i:arr){
        s.insert(i);
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        if(!s.count(arr[i]-1)){
            int curr=arr[i];
            int currs=1;
            while(s.count(curr+1)){
                curr+=1;
                currs+=1;
            }
            maxi=max(maxi,currs);
        }
    }
    return maxi;
}