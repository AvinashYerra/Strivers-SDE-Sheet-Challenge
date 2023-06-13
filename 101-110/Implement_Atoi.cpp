#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int n=str.size();
   int i=0;
   while(i<n && str[i]==' '  && !isdigit(str[i])){
       i++; 
   }
   str.substr(i);
   int sign=+1;
   if(str[0]=='-') sign=-1;
   int mini=INT_MIN;
   int maxi=INT_MAX;
   long ans=0;
    i=(str[0]=='+'|| str[0]=='-') ? 1:0;
   while(i<n){
       //if(str[i]==' ' || !isdigit(str[i])) break;
       if (isdigit(str[i])) {
         ans = ans * 10 + (str[i] - '0');
       }
       if(sign==-1 && -1*ans<mini) return mini;
       if(sign==1 && 1*ans>maxi) return maxi;
       i++;
   }
   return (int)sign*ans;
}