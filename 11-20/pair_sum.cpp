#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   int n=arr.size();
   vector<vector<int>>v;
   sort(arr.begin(),arr.end());
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         
         if(arr[i]+arr[j]==s){
            vector<int>temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            v.push_back(temp);
         }
         
      }
   }
   return v;
}