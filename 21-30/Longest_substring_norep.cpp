#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
    int n=s.size();
    int i=0;
    int j=0;
    int mx=-1;
    map<char,int>mp;
    while(j<n){
        mp[s[j]]++;
        if(mp.size()==j-i+1){
            mx=max(mx,j-i+1);
        }else if(mp.size()<j-i+1){
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
            i++;
        }
        j++;
    }
    return mx;
}