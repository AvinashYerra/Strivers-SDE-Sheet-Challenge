#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
   int cnt=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
       for(int j=i+1;j<n-2;j++){
           int k=j+1;
           int l=n-1;
           while(k<l){
             int t=arr[i]+arr[j]+arr[k]+arr[l];
               if (t == target) {
                cnt++;
                 k++;
                 l--;
                
               } else if (t < target) {
                 k++;
                 
               }else{
                   l--;
               }
           }
       } 
    }
    if(cnt>=1) return "Yes";
    return "No";


}
