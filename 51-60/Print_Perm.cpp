#include <bits/stdc++.h> 
void help(int l,int r, string &s,vector<string>&ans){
    if(l==r) ans.push_back(s);
    for(int i=l;i<=r;i++){
        swap(s[l],s[i]);
        help(l+1,r,s,ans);
        swap(s[l],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    int n=s.size();
    help(0,n-1,s,ans);
    sort(ans.begin(),ans.end());
    return ans;
}