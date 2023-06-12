#include<bits/stdc++.h>
    void nsl(vector<int>&heights,int n,vector<int>&left,int x){
        
        stack<pair<int,int>>s;
        for(int i=0;i<n;i++){
            if(s.size()==0){
                left.push_back(x);
            }else if(s.size()>0 && s.top().first<heights[i]){
                left.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    left.push_back(x);
                    
                }else{
                    left.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
    }
     void nsr(vector<int>&heights,int n,vector<int>&right,int x){
        
        stack<pair<int,int>>s;
        for(int i=n-1;i>=0;i--){
            if(s.size()==0){
                right.push_back(x);
            }else if(s.size()>0 && s.top().first<heights[i]){
                right.push_back(s.top().second);
            }else if(s.size()>0 && s.top().first>=heights[i]){
                while(s.size()>0 && s.top().first>=heights[i]){
                    s.pop();
                }
                if(s.size()==0){
                    right.push_back(x);
                    
                }else{
                    right.push_back(s.top().second);
                }
            }
            s.push({heights[i],i});
        }
         reverse(right.begin(),right.end());
    }
    
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int n=heights.size();
        int ans=-1;
        vector<int>left;
        vector<int>right;
        nsl(heights,n,left,-1);
        nsr(heights,n,right,n);
        for(int i=0;i<heights.size();i++){
            int width=right[i]-left[i]-1;
            int area=(width)*heights[i];
            if(area>ans){
                ans=area;
            }
        }
        return ans;
 }