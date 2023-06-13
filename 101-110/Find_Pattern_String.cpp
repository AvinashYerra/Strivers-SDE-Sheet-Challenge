#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    int n=p.size();
    for(int i=0;i<s.size();i++){
        if(s[i]==p[0]){
            string temp=s.substr(i,n);
            if(temp==p) return true;
        }
    }
    return false;
}