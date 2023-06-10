#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    for(int i=0;i<n;i++){
        if(maxh.size()==minh.size()){
        if(!minh.empty()){
            if(minh.top()<arr[i]){
                maxh.push(minh.top());
                minh.pop();
                minh.push(arr[i]);
            }else{
                maxh.push(arr[i]);
            }
        }else{
            maxh.push(arr[i]);
        }
     }else{
         if(!maxh.empty()){
             if(maxh.top()>arr[i]){
                 minh.push(maxh.top());
                 maxh.pop();
                 maxh.push(arr[i]);
             }else{
                 minh.push(arr[i]);
             }
         }else{
             minh.push(arr[i]);
         }
     }
     if(maxh.size()==minh.size()){
         cout<<(maxh.top()+minh.top())/2<<" ";
     }else{
         cout<<maxh.top()<<" ";
     }
    }
}