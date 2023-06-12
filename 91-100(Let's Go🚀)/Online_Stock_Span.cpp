#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n=price.size();
    vector<int>v;
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            v.push_back(-1);
        }else if(st.size()>0 && st.top().first>price[i]){
            v.push_back(st.top().second);
        }else if(st.size()>0 && st.top().first<=price[i]){
            while(st.size()>0 && st.top().first<=price[i]){
                st.pop();
            }
            if(st.size()==0) v.push_back(-1);
            else if(st.top().first>price[i]){
                v.push_back(st.top().second);
            }
        }
        st.push({price[i],i});
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
         ans.push_back(i-v[i]);
    }
    return ans;

}