#include <bits/stdc++.h> 
void help(int ind,string ip,string op,unordered_map<string,int>&mp,vector<string>&ans){
    if(ind==ip.size()){
        op.pop_back();
        ans.push_back(op);
        op.push_back(' ');
        return;
    } 
    for(int i=ind;i<ip.size();i++){
        if(mp.find(ip.substr(ind,i-ind+1))!=mp.end()){
            string prev=op;
            op+=ip.substr(ind,i-ind+1);
            op.push_back(' ');
            help(i+1,ip,op,mp,ans);
            op=prev;
        }

    }
    //return;
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string>ans;
    string op="";
    unordered_map<string,int>mp;
    for(auto s:dictionary){
        mp[s]++;
    }
    help(0,s,op,mp,ans);
    return ans;

}