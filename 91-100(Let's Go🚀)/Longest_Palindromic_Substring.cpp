#include<bits/stdc++.h>
string got(int l,int r,string s){
        string temp;
        for(int i=l;i<=r;i++){
            temp+=s[i];
        }
        return s;
    }
string longestPalinSubstring(string s)
{
    // Write your code here.
     int n=s.size();
     int maxi=0;
    string res="";
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>maxi){
                    maxi=r-l+1;
                    res=s.substr(l,r-l+1);
                }
                l--;
                r++;
            }
            l=i,r=i+1;
             while(l>=0 && r<n && s[l]==s[r]){
               if (r - l + 1 > maxi) {
                 maxi = r - l + 1;
                 res=s.substr(l,r-l+1);
               }
               l--;
               r++;
             }
        }
    
        return res;
}