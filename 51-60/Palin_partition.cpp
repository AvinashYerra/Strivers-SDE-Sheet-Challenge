#include <bits/stdc++.h> 
bool ispalin(string s,int start,int end){
    while(start<=end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}
void help(int ind,string &s,vector<string>&path,vector<vector<string>>&ans){
    if(ind==s.size()){
        ans.push_back(path);
        return ;
    }
    for(int i=ind;i<s.size();i++){
        if( ispalin(s,ind,i)){
            path.push_back(s.substr(ind,i-ind+1));
            help(i+1,s,path,ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>>ans;
    vector<string>path;
    help(0,s,path,ans);
    return ans;
}