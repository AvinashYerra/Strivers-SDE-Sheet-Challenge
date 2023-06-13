#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    map<char,int>mp;
    for(int i=0;i<str1.size();i++){
        mp[str1[i]]++;
    }
    for(int i=0;i<str2.size();i++){
        mp[str2[i]]--;
        if(mp[str2[i]]==0) mp.erase(str2[i]);
    }
    return mp.size()==0;
}