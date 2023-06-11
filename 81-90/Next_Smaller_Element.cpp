#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        if(st.size()==0){
            ans.push_back(-1);
        }else if(st.size()>0 && st.top()<arr[i]){
            ans.push_back(st.top());
        }else if(st.size()>0 && st.top()>=arr[i]){
            while(st.size()>0 && st.top()>=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                ans.push_back(-1);
            }else if(st.top()<arr[i]){
                ans.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}